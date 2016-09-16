#include <stdlib.h>
#include "uut.h"

int main() {
	int i;

	double prevVal = 0;
	double CurrentVal = 0;

	for (i=2; i<1000; i++) { //starting from 1 gives incorrect results
		prevVal = ln(30,i);

		printf("for %d: %.30f\n", i, prevVal);

		if(prevVal == CurrentVal) {
			printf("\n\nconverges at: %d", i);
			return i;
		}

		CurrentVal = prevVal;
		
	}

	return 0;
}
