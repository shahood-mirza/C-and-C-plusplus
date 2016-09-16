/*
Dynamic Structures
By: Shahood Mirza

Description:
This program will allow the user to specify the amount of data to be stored into a structure,
then it will allocate enough memory to fill the structure, and will display the items entered
in a table format
*/

#include "Main.h"

///////////////////////////////////////////////////////////////////////////
////////////////////////STRUCTURE VIEW FUNCTION////////////////////////////
void showStruct (struct ProdPurchase *Items, int count)
{
	int i;

	printf("Items Currently Entered Into Structure\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("PartID	RepName			UnitPrice 	Qty		TotalCost");

	for(i=0; i<count; i++)	//as data is entered into the structure it will be displayed in table format
	{
			printf("\n%s	", (Items+i)->partID);
			printf("%-20s	", (Items+i)->repName);	//20 characters are designated for repName at output
			printf("$%.2f		", (Items+i)->unitPrice);
			printf("%d		", (Items+i)->qty);
			printf("$%.2f", (Items+i)->totalCost);
	}

	printf("\n-----------------------------------------------------------------------------\n\n");
}

///////////////////////////////////////////////////////////////////////////
//////////////////////STRUCTURE FILLING FUNCTION///////////////////////////
void fillStruct (struct ProdPurchase *Items)
{
	int i, insertions=0; 
	char price[4], quant[4];

	system("cls");

	printf("\nHow many products will be inserted?\n");
	while(insertions <= 0)	//make sure number entered is positive
	{
		printf("Please Enter a Positive Number: ");
		fflush(stdin);
		scanf_s("%d", &insertions);
	}

	//allocate memory according to number of insertions
	Items = (struct ProdPurchase *) malloc(insertions*sizeof(struct ProdPurchase));

	system("cls");

	for(i=0; i<insertions; i++)
	{
		printf("Enter the PartID for the Item (XXXXX): ", i+1);
		fflush(stdin);
		fgets((Items+i)->partID, 7, stdin);	//5 chars for partID, 1 for \0, 1 for newline
		(Items+i)->partID[strlen((Items+i)->partID)-1] = '\0';	//eliminate newline from fgets

		printf("Enter Representative Name for ID-%s: ", (Items+i)->partID);	
		fflush(stdin);
		fgets((Items+i)->repName, ArraySize, stdin);
		(Items+i)->repName[strlen((Items+i)->repName)-1] = '\0';	//eliminate newline from fgets

		printf("Enter Unit Price for ID-%s: $", (Items+i)->partID);
		fflush(stdin);
		while(!((Items+i)->unitPrice = atof(fgets(price, 4, stdin))))	//make sure user enters a number
		{
			printf("Please Enter A Price Value: $", (Items+i)->partID);
			fflush(stdin);
		}

		printf("Enter the Quantity of ID-%s Purchased: ", (Items+i)->partID);
		fflush(stdin);
		while(!((Items+i)->qty = atoi(fgets(quant, 3, stdin))))	//make sure user enters a number
		{
			printf("Please Enter A Valid Quantity: ", (Items+i)->partID);
			fflush(stdin);
		}
		
		(Items+i)->totalCost = (Items+i)->unitPrice * (Items+i)->qty;	//totalcost calculatino

		system("cls");
		showStruct(Items, i+1);
	}
}

///////////////////////////////////////////////////////////////////////////
/////////////////MAIN FUNCTION - PROGRAM STARTS HERE///////////////////////
int main (void)
{
	struct ProdPurchase *Items = NULL;
	char choice = ' ';

	while(choice != '2')
	{
		system("cls");

		printf("\nSelect an Option (1-2):\n\n");
		printf("1. Fill Structure Array\n");
		printf("2. Exit\n");

		choice = getch();

		switch(choice)
		{
			case '1':
			{
				fillStruct(Items);
				printf("Data Entry Complete! Press Any Key to Continue...");

				free(Items);	//free allocated memory
				Items = NULL;

				getch();
				break;
			}
			case '2':
			{
				break;
			}
			default:
			{
				printf("Invalid Entry. Press Any Key to Continue...");
				getch();
			}
		}
	}

	return 0;
}