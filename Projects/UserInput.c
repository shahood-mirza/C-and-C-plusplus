/*
User Input
By: Shahood Mirza

Description:
This program calculates resistor variances as according to tolerences for up to four user inputted resistances 
and calculates the thevenin voltage and resistance as well as capacitor voltage values and displays them to the user.
The circuit is taken from the lab overview document.
*/

#include "Main.h"

int main (void)
{
	float res1, res2, res3, res4, tol1, tol2, tol3, tol4, resMin1, resMin2, resMin3, resMin4, resMax1, resMax2, resMax3, resMax4;
	float cap, volt, capVolt;
	float rThevMin, rThev, rThevMax, vThevMin, vThev, vThevMax;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///// USER INPUT ///////////////////////////////////////////////////////////////////////////////////////////

	printf("Enter a value for R1 (In Ohms): ");
	scanf("%f", &res1);
	printf("Enter a tolerence value for R1: ");
	scanf("%f", &tol1);

	printf("Enter a value for R2 (In Ohms): ");
	scanf("%f", &res2);
	printf("Enter a tolerence value for R2: ");
	scanf("%f", &tol2);

	printf("Enter a value for R3 (In Ohms): ");
	scanf("%f", &res3);
	printf("Enter a tolerence value for R3: ");
	scanf("%f", &tol3);

	printf("Enter a value for R4 (In Ohms): ");
	scanf("%f", &res4);
	printf("Enter a tolerence value for R4: ");
	scanf("%f", &tol4);

	printf("\nEnter a value for the voltage supply (In Volts): ");
	scanf("%f", &volt);
	printf("Enter a value for the load capacitor (In Microfarads): ");
	scanf("%f", &cap);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///// CALCULATIONS /////////////////////////////////////////////////////////////////////////////////////////

	//the inputted resistance variances are calculated according to each tolerance
	resMin1 = res1 * (1 - (tol1 / 100));
	resMax1 = res1 * (1 + (tol1 / 100));

	resMin2 = res2 * (1 - (tol2 / 100));
	resMax2 = res2 * (1 + (tol2 / 100));

	resMin3 = res3 * (1 - (tol3 / 100));
	resMax3 = res3 * (1 + (tol3 / 100));

	resMin4 = res4 * (1 - (tol4 / 100));
	resMax4 = res4 * (1 + (tol4 / 100));

	//these calculations are made according the circuit in the lab overview document
	rThev = (1 / ((1 / res1) + (1 / res2))) + res3 + res4;
	rThevMin = (1 / ((1 / resMin1) + (1 / resMin2))) + resMin3 + resMin4;
	rThevMax = (1 / ((1 / resMax1) + (1 / resMax2))) + resMax3 + resMax4;

	vThev = (res2 * volt) / (res1 + res2);
	vThevMin = (resMin2 * volt) / (resMin1 + resMin2);
	vThevMax = (resMax2 * volt) / (resMax1 + resMax2);

	//The inputted capacitance value must be converted to farads to calculate the capacitor voltage
	cap /= 1000000;
	capVolt = vThev * (1 - (exp(-0.002/(rThev*cap))));

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///// CONSOLE OUTPUT ///////////////////////////////////////////////////////////////////////////////////////

	//The output is formatted into a table like format for increased readability
	printf("\n\nR1 - Min: %6.0f Ohms | Nominal: %6.0f Ohms | Max: %6.0f Ohms | Tol: +-%6.0f%%\n", resMin1, res1, resMax1, tol1);
	printf("R2 - Min: %6.0f Ohms | Nominal: %6.0f Ohms | Max: %6.0f Ohms | Tol: +-%6.0f%%\n", resMin2, res2, resMax2, tol2);
	printf("R3 - Min: %6.0f Ohms | Nominal: %6.0f Ohms | Max: %6.0f Ohms | Tol: +-%6.0f%%\n", resMin3, res3, resMax3, tol3);
	printf("R4 - Min: %6.0f Ohms | Nominal: %6.0f Ohms | Max: %6.0f Ohms | Tol: +-%6.0f%%\n", resMin4, res4, resMax4, tol4);

	//Six spaces are alloted for all numeric values
	//Thevenin resistance and voltage values are rounded to four decimal places
	printf("\nThevenin Voltage - Min: %+6.4fV | Nominal: %+6.4fV | Max: %+6.4fV\n", vThevMin, vThev, vThevMax);

	printf("\nThevenin Resistance - Min: %6.4f Ohms | Nominal: %6.4f Ohms | Max: %6.4f Ohms\n", rThevMin, rThev, rThevMax);

	printf("\nCapacitor Voltage: %6.4fV\n", capVolt);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	getch();
	return 0;
}