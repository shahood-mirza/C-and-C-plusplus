/*
Arrays and Random Numbers
By: Shahood Mirza

Description:
This program will generate 100 random numbers between 1 and 15, tally the occurrences of each number,
display the average numbers between the occurrence of the nummber 3 and display the first and last number generated
*/

#include "Main.h"

int main (void)
{
	///////////////////////////////////////////////////////////////////////////
	/////////////////////////PROGRAM VARIABLES/////////////////////////////////
	int i, j, counter = 0, sumBetween = 0;
	int RandNum[100], tally[15];

	///////////////////////////////////////////////////////////////////////////
	
	printf("RANDOM NUMBER GENERATOR\n\n");

	srand(time(NULL));	//this function, coupled with rand(), will generate the random numbers

	for(j=0; j<15; j++)
	{
		tally[j] = 0;	//initially, the tally array must be initialized to zero values
						//this way, we can add to the array
	}

	for(i=0; i<100; i++)
	{
		RandNum[i] = rand() % 15 + 1;	//initialize the RandNum array with numbers between 1-15

		for(j=1; j<=15; j++)
		{
			if(RandNum[i] == j)	//each time a number is generated the tally for that number must be increased by one
				tally[j-1]++;
		}

		if(RandNum[i] == 3)	//in order to find the average numbers between #3 we need to add 1 for each generated non-three number to a counter
		{
			sumBetween += counter;	//once a three is generated we add the counter to the sum of all numbers between a generated #3
									//once all numbers are generated, we can divide this number by the tally for #3 to get the average
			counter = 0;
		}
		
		counter++;
	}
	
	///////////////////////////////////////////////////////////////////////////
	//////////////////////////PROGRAM OUTPUT///////////////////////////////////
	printf("Tally of Occurrences:\n");

	for(j=1; j<=15; j++)
	{
		printf("%d: %d\n", j, tally[j-1]);	//output each number and its tally
	}

	printf("\nAverage numbers between occurence of #3: %d\n", (sumBetween / tally[2]));
	
	printf("First Random Number:	%d\n", RandNum[0]);
	printf("Last Random Number:	%d", RandNum[99]);

	getch();
	return 0;
}