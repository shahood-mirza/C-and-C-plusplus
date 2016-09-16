#include <stdbool.h>
#include <math.h>  

double nop(double x, int n);
double ln(double x, int n);

int main (int argc, char *argv[] )
{
	double result;
	
	result = ln(atof(argv[1]), 1000);

	printf("ln: %f", result);
	return 0;
}

double nop(double x, int n) {
	return x;
}

double ln(double x, int n) {
	int i;
	double result = 0;
	bool invert = false;

	if(x > 2) {
		x = 1/x; //taylor series works only for  0 < x < 2
		invert = true; //we can use this to solve for remaining nums
	}

	if (x <= 0) {
		return 0; //ln of 0 or less is invalid
	}

	for(i=1; i<n; i++) {
		if(i%2 == 1) //add for odd, subtract for even
			result += pow((x-1), i) / i;
		else
			result -= pow((x-1), i) / i;
	}
	
	if(invert)
		result *= -1;

	return result;
}
