#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <intrin.h>

typedef double (__stdcall *f_ln)(double x, int n);
typedef double (__stdcall *f_nop)(double x, int n);

void timeLoop(FILE *file, char* DLL, f_ln ln, f_nop nop);
void writeCSV(FILE *file, char* DLL, int timeLN, int timeNOP);

int main() {
	remove("results.csv"); //remove old results file if it exists
	
	FILE *resFile;
	resFile = fopen ("results.csv", "ab");
	if (resFile!=NULL) {
		fprintf (resFile, "DLL Name,UUT Time,Overhead Time\n"); //column headers
		printf ("DLL Name,UUT Time,Overhead Time\n"); //writing for times.csv
	}
	
	//clock for timing loop
	clock_t t;
	t = clock();
	
	//array of DLL files to be used
	char* DLL[] = {"uut.gcc.dll","uut.gcc.OPT.dll","uut.int.dll","uut.int.OPT.dll","uut.ms.dll","uut.ms.OPT.dll"};

	int i;
	long fileSize=0;

	//stop loop after 1 second or when file is 1MB
	while (((clock()-t) < 250) && (fileSize < 1000000)) {
		for (i=0; i<6; i++) {
			HINSTANCE hGetProcIDDLL = LoadLibrary(DLL[i]);

			if (!hGetProcIDDLL) {
				printf("could not load the dynamic library");
				return 1;
			}

			//resolve function addresses
			f_ln ln = (f_ln)GetProcAddress(hGetProcIDDLL, "ln");
			if (!ln) {
				printf("could not locate the ln function");
				return 1;
			}

			f_nop nop = (f_nop)GetProcAddress(hGetProcIDDLL, "nop");
			if (!nop) {
				printf("could not locate the nop function");
				return 1;
			}

			timeLoop(resFile, DLL[i], ln, nop);
		}

		//check filesize after each iteration
		fseek(resFile,0L,SEEK_END);
		fileSize = ftell(resFile);
		
	}
	
	//close file after processing is complete
	fclose(resFile);

	return 0;
}

void timeLoop(FILE *resFile, char* DLL, f_ln ln, f_nop nop) {
	LARGE_INTEGER StartingTime, EndingTime, ElapsedTimeLN, ElapsedTimeNOP;
	LARGE_INTEGER Frequency;

	//starting performance counter
	QueryPerformanceFrequency(&Frequency); 
	QueryPerformanceCounter(&StartingTime);
	
	int i;
	for (i=0; i<10; i++) {
		//code to be timed
		int b[9];
		ln(30, 865);
		__cpuid(b, i);// synchronization fence

	}
		
	//ending counter
	QueryPerformanceCounter(&EndingTime);
	ElapsedTimeLN.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	
	//converting to microseconds
	ElapsedTimeLN.QuadPart *= 1000000;
	ElapsedTimeLN.QuadPart /= Frequency.QuadPart;

	//starting performance counter
	QueryPerformanceFrequency(&Frequency); 
	QueryPerformanceCounter(&StartingTime);

	for (i=0; i<10; i++) {
		//code to be timed
		int b[9];
		nop(30, 865);
		__cpuid(b, i);// synchronization fence
	}
		
	//ending counter
	QueryPerformanceCounter(&EndingTime);
	ElapsedTimeNOP.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	
	//converting to microseconds
	ElapsedTimeNOP.QuadPart *= 1000000;
	ElapsedTimeNOP.QuadPart /= Frequency.QuadPart;

	writeCSV(resFile, DLL, ElapsedTimeLN.QuadPart/10, ElapsedTimeNOP.QuadPart/10);
}

void writeCSV(FILE *resFile, char* DLL, int timeLN, int timeNOP) {
	//writing results to csv
	if (resFile!=NULL) {
		fprintf (resFile, "%s,%d,%d\n", DLL, timeLN, timeNOP);
		printf("%s,%d,%d\n", DLL, timeLN, timeNOP); //writing for times.csv
	}
}