#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ArraySize 20

//Function Prototypes
void showStruct (struct ProdPurchase *Items, int count);
void fillStruct (struct ProdPurchase *Items);

//Structure Types
struct ProdPurchase
{
	char partID[7];
	char repName[ArraySize];
	float unitPrice;
	int qty;
	float totalCost;
};