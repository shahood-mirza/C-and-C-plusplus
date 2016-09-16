/*
Context Menu
By: Shahood Mirza

Description:
This program calculates load voltages and currents based on capcitor, inductor and resistor loads.
The user has the option of selecting which load they need values for and is able to insert resistor and
source voltage values.

Formulas Used:
rThev = (1 / ((1 / r1) + (1 / r2))) + r3 + r4;
vThev = (r2 * volts) / (r1 + r2);

CapacitorVolts = vThev * (1 - (exp(-time / (rThev * capacitance))));
IncductorVolts = vThev * (exp((-rThev * time) / inductance));
ResistorVolts = (vThev / (rThev + resistance)) * (rThev + resistance);

CapacitorCurrent = (vThev / rThev) * (exp(-time / (rThev * capacitance)));
InductorCurrent = (vThev / rThev) * (1 - (exp((-rThev * time) / inductance)));
ResistorCurrent = vThev / (rThev + resistance);
*/

#include "Main.h"

///////////////////////////////////////////////////////////////////////////
///////////////////////GLOBAL VARIABLES////////////////////////////////////
float rThev, vThev, time;

///////////////////////////////////////////////////////////////////////////
////////////////////GLOBAL THEVENIN VALUE FUNCTION/////////////////////////
void ThevCalc(float r1, float r2, float r3, float r4, float volts)
{
	rThev = (1 / ((1 / r1) + (1 / r2))) + r3 + r4;
	vThev = (r2 * volts) / (r1 + r2);
}

///////////////////////////////////////////////////////////////////////////
////////////////////VOLTAGE CALCULATOR FUNCTION////////////////////////////
float LoadVoltCalc (float loadInput, char formula)	//the 'formula' character acts as a flag to signy which formula to use
{
	float calcVolt;
	time /= 1000;	//convert milliseconds to seconds
	loadInput /= 1000000;	//convert microHenrys/microFarads to Henrys/Farads

	if(formula == 'c')
		calcVolt = vThev * (1 - (exp(-time / (rThev * loadInput))));
	else if (formula == 'i')
		calcVolt = vThev * (exp((-rThev * time) / loadInput));
	else if (formula == 'r')
		calcVolt = (vThev / (rThev + loadInput)) * (rThev + loadInput);	//current must be calculated first in order to find the voltage

	return calcVolt;
}

///////////////////////////////////////////////////////////////////////////
////////////////////CURRENT CALCULATOR FUNCTION////////////////////////////
float LoadCurrCalc (float loadInput, char formula)		//the 'formula' character acts as a flag to signy which formula to use
{
	float calcCurr;
	time /= 1000;	//convert milliseconds to seconds
	loadInput /= 1000000;	//convert microHenrys/microFarads to Henrys/Farads

	if(formula == 'c')
		calcCurr = (vThev / rThev) * (exp(-time / (rThev * loadInput)));
	else if (formula == 'i')
		calcCurr = (vThev / rThev) * (1 - (exp((-rThev * time) / loadInput)));
	else if (formula == 'r')
		calcCurr = vThev / (rThev + loadInput);

	return calcCurr;
}

///////////////////////////////////////////////////////////////////////////
/////////////////MAIN FUNCTION - PROGRAM STARTS HERE///////////////////////
int main (void)
{
	char choice;
	float res1=0, res2=0, res3=0, res4=0, volts=0;	//pre-assigned variables
	float loadInput;	//user input variable

	while(TRUE)
	{
		system("cls");
		
		printf("Enter a number:\n\n");
		printf("1. Enter Resistor and Voltage Values\n");
		printf("2. Solve for Capacitor Load\n");
		printf("3. Solve for Inductor Load\n");
		printf("4. Solve for Resistor Load\n");
		printf("5. Exit\n");

		choice = getch();

		if (choice == '2' || choice == '3' || choice == '4')	//make sure user has entered resistor values prior to continuing
		{
			if(res1 <= 0.0 || res2 <= 0.0 || res3 <= 0.0 || res4 <= 0.0 || volts <= 0.0)
			{
				printf("\nPlease Enter Correct Resistor and Voltage Values First.\n");
				printf("Press Any Key to Continue...");
				getch();
				continue;
			}
		}

		system("cls");

		switch (choice)
		{
			case '1' :
			{
				printf("Enter a value for R1 (In Ohms): ");
				fflush(stdin);
				while(scanf("%f", &res1) != TRUE)	//check to make sure the user has entered a correct number before continuing
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}

				printf("Enter a value for R2 (In Ohms): ");
				fflush(stdin);
				while(scanf("%f", &res2) != TRUE)
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}
				
				printf("Enter a value for R3 (In Ohms): ");
				fflush(stdin);
				while(scanf("%f", &res3) != TRUE)
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}
				
				printf("Enter a value for R4 (In Ohms): ");
				fflush(stdin);
				while(scanf("%f", &res4) != TRUE)
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}
				
				printf("\nEnter the source voltage (In Volts): ");
				fflush(stdin);
				while(scanf("%f", &volts) != TRUE)
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}
				
				ThevCalc(res1, res2, res3, res4, volts);
				
				printf("\nAll Values have been stored. Press Any Key to Continue.");
				getch();
				break;
			}
			case '2' :
			{
				printf("Enter Load Capacitor Capacitance (In microFarads): ");
				fflush(stdin);
				while(scanf("%f", &loadInput) != TRUE)
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}
				
				printf("Enter Time Value (In milliseconds): ");
				fflush(stdin);
				while(scanf("%f", &time) != TRUE)
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}
				
				printf("\nThe voltage accross the capacitor is: %.2fV\n", LoadVoltCalc(loadInput, 'c'));
				printf("The current through the capacitor is: %.2fA\n\n", LoadCurrCalc(loadInput, 'c'));
				
				printf("Press Any Key to Continue...");
				getch();
				break;
			}
			case '3' :
			{
				printf("Enter Load Inductor Inductance (In microHenrys): ");
				fflush(stdin);
				while(scanf("%f", &loadInput) != TRUE)
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}
				
				printf("Enter Time Value (In milliseconds): ");
				fflush(stdin);
				while(scanf("%f", &time) != TRUE)
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}

				printf("\nThe voltage accross the inductor is: %.2fV\n", LoadVoltCalc(loadInput, 'i'));
				printf("The current through the inductor is: %.2fA\n\n", LoadCurrCalc(loadInput, 'i'));
				
				printf("Press Any Key to Continue...");
				getch();
				break;
			}
			case '4' :
			{
				printf("Enter Load Resistor Resistance (In Ohms): ");
				fflush(stdin);
				while(scanf("%f", &loadInput) != TRUE)
				{
					while(getchar() != '\n');
						printf("Please Enter a Number: ");
				}

				printf("\nThe voltage accross the load resistor is: %.2fV\n", LoadVoltCalc(loadInput, 'r'));
				printf("The current through the load resistor is: %.2fA\n\n", LoadCurrCalc(loadInput, 'r'));

				printf("Press Any Key to Continue...");
				getch();
				break;
			}
			case '5' :
			{
				return 0;	//exits the program
			}
			default :
			{
				printf("Invalid Entry. Press Any Key to Continue.");
				getch();
			}
		}
	}
}