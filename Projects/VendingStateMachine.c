/*
State Machine
By: Shahood Mirza

Description:
This program acts as a virtual vending machine. The user is able to deposit coins, 
return coins and purchase items as long as they are in stock.
*/

#include "Main.h"

int main (void)
{
	///////////////////////////////////////////////////////////////////////////
	///////////////////////PRODUCT PRICE CONSTANTS/////////////////////////////
	float const cokePrice=1.25, dewPrice=1.00, spritePrice=1.50, nesteaPrice=2.00, dryPrice=0.75;
	
	///////////////////////////////////////////////////////////////////////////
	/////////////////////////PROGRAM VARIABLES/////////////////////////////////
	int loopFlag = 1;
	int cokeStk=6, dewStk=10, spriteStk=4, nesteaStk=6, dryStk=8;
	float money = 0.00;
	char choice, menu;

	///////////////////////////////////////////////////////////////////////////

	printf("Vending Machine v2.0\n\n");
	Sleep(1000);

	while(1)
	{
		///////////////////////////////////////////////////////////////////////////
		/////////////////////////////MAIN MENU/////////////////////////////////////
		system("cls");	//The console window is cleared to decrease output clutter
		printf(" ------------------\n");
		printf("| Balance: $%.2f   |\n", money);
		printf(" ------------------\n\n");
		printf("What Would You Like to Do? (Choose 1-3):\n\n");
		printf("1. Deposit Coins\n");
		printf("2. Return Change\n");
		printf("3. Buy Item\n");

		menu = getch(); 
		//Characters are used instead of integers for all of the main switch functions
		//This prevents any user input errors and removes the need to press the 'Enter' key after a selection
		//Incorrect key presses are handled in the 'default' for each switch statement

		switch(menu)
		{
			///////////////////////////////////////////////////////////////////////////
			/////////////////////////////COIN DEPOSIT//////////////////////////////////
			case '1':
			{
				loopFlag = 1;	//The loopFlag variable is used as a check to break from the coin deposit loop

				while(loopFlag)
				{
					system("cls");
					printf(" ------------------\n");
					printf("| Balance: $%.2f   |\n", money);
					printf(" ------------------\n\n");
					printf("Please Deposit Coins. (Choose 1-6)\n\n");
					printf("1. Nickel\n");
					printf("2. Dime\n");
					printf("3. Quarter\n");
					printf("4. Loonie\n");
					printf("5. Toonie\n");
					printf("\n6. Return to Main Menu\n\n");

					menu = getch();
					//Once the user chooses to deposit a certain coin, their balance will be updated

					switch(menu)
					{
						/////NICKEL/////
						case '1':
						{
							money += 0.05;
							break;
						}
						/////DIME/////
						case '2':
						{
							money += 0.10;
							break;
						}
						/////QUARTER/////
						case '3':
						{
							money += 0.25;
							break;
						}
						/////LOONIE/////
						case '4':
						{
							money += 1.00;
							break;
						}
						/////TOONIE/////
						case '5':
						{
							money += 2.00;
							break;
						}
						case '6':
						{
							//The loopFlag variable is modified to 0
							//This will break from the loop and return to the main menu
							loopFlag = 0;
							break;
						}
						default:
						{
							printf("Invalid Selection; Please Choose Again. (Press Any Key to Continue)\n");
							getch();
							break;
						}
					}
				}
				break;
			}
			///////////////////////////////////////////////////////////////////////////
			/////////////////////////////COIN RETURN///////////////////////////////////
			case '2':
			{
				system("cls");
				printf(" ------------------\n");
				printf("| Balance: $%.2f   |\n", money);
				printf(" ------------------\n\n");
				printf("Are you sure you want to return all coins? (Y/N)\n\n");

				choice = getch();
				//Coins are only returned once the user confirms their choice

				if((choice=='y')||(choice=='Y'))
				{
					printf("Returned $%.2f coins. (Press Any Key to Continue)\n", money);
					money = 0.0;
					getch();
					break;
				}
				else if((choice=='n')||(choice=='N'))
				{
					printf("Coins not returned. (Press Any Key to Continue)\n");
					getch();
					break;
				}
				else
				{
					printf("Invalid Entry. Coins not returned. (Press Any Key to Continue)\n");
					getch();
					break;
				}
			}
			///////////////////////////////////////////////////////////////////////////
			/////////////////////////////ITEM PURCHASE/////////////////////////////////
			case '3':
			{
				loopFlag = 1;
				while(loopFlag)
				{
					//The products are displayed in a table-like format for readability
					system("cls");
					printf(" ------------------\n");
					printf("| Balance: $%.2f   |\n", money);
					printf(" ------------------\n\n");
					printf("What Would You Like to Purchase? (Choose 1-6)\n\n");
					printf("	Item		Price		Stock\n");
					printf("1. Coca-Cola	 -	$%1.2f	  -	  %-d\n", cokePrice, cokeStk);
					printf("2. Mountain Dew  -	$%1.2f	  -	  %-d\n", dewPrice, dewStk);
					printf("3. Sprite	 -	$%1.2f	  -	  %-d\n", spritePrice, spriteStk);
					printf("4. Nestea	 -	$%1.2f	  -	  %-d\n", nesteaPrice, nesteaStk);
					printf("5. Canada Dry	 -	$%1.2f	  -	  %-d\n", dryPrice, dryStk);
					printf("\n6. Return to Main Menu\n\n");

					menu = getch();

					switch(menu)
					{
						//When the user makes a product selection, certain checks are administered
						//before the product is allowed to be dispensed

						////////////////////////COCA-COLA////////////////////////
						case '1':
						{
							//First, the item must be in stock
							//If the it is not, the user will not lose the money they inserted
							if (cokeStk == 0)
							{
								printf("Out of stock. (Press Any Key to Continue)\n");
								getch();
							}

							//Next we must check if the user has sufficient balance to purchase the item
							//If the balance is acceptable, the product will be dispensed
							//The user will also be charged for the purchase
							else if(money >= cokePrice)
							{
								cokeStk--;
								money -= cokePrice;
								
								//When an item is purchased, the program will use delays 
								//to simulate a dispensing vending machine
								printf("Dispensing Coca-Cola");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf("Enjoy!");
								Sleep(1000);
							}
							//If the balance is not acceptable, the product will not be dispensed
							//The user will be told how much more money they need in order to purchase the item
							//The user will not lose any money inserted
							else
							{
								printf("Please Insert $%.2f More to Purchase the Item. (Press Any Key to Continue)\n", (cokePrice - money));
								getch();
							}
							break;
						}
						////////////////////////MOUNTAIN DEW////////////////////////
						case '2':
						{

							if (dewStk == 0)
							{
								printf("Out of stock. (Press Any Key to Continue)\n");
								getch();
							}
							else if(money >= dewPrice)
							{
								dewStk--;
								money -= dewPrice;

								printf("Dispensing Mountain Dew");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf("Enjoy!");
								Sleep(1000);
							}
							else
							{
								printf("Please Insert $%.2f More to Purchase the Item. (Press Any Key to Continue)\n", (dewPrice - money));
								getch();
							}
							break;
						}
						////////////////////////SPRITE////////////////////////
						case '3':
						{
							if (spriteStk == 0)
							{
								printf("Out of stock. (Press Any Key to Continue)\n");
								getch();
							}
							else if(money >= spritePrice)
							{
								spriteStk--;
								money -= spritePrice;

								printf("Dispensing Sprite");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf("Enjoy!");
								Sleep(1000);
							}
							else
							{
								printf("Please Insert $%.2f More to Purchase the Item. (Press Any Key to Continue)\n", (spritePrice - money));
								getch();
							}
							break;
						}
						////////////////////////NESTEA////////////////////////
						case '4':
						{
							if (nesteaStk == 0)
							{
								printf("Out of stock. (Press Any Key to Continue)\n");
								getch();
							}
							else if(money >= nesteaPrice)
							{
								nesteaStk--;
								money -= nesteaPrice;

								printf("Dispensing Nestea");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf("Enjoy!");
								Sleep(1000);
							}
							else
							{
								printf("Please Insert $%.2f More to Purchase the Item. (Press Any Key to Continue)\n", (nesteaPrice - money));
								getch();
							}
							break;
						}
						////////////////////////CANADA DRY////////////////////////
						case '5':
						{
							if (dryStk == 0)
							{
								printf("Out of stock. (Press Any Key to Continue)\n");
								getch();
							}
							else if(money >= dryPrice)
							{
								dryStk--;
								money -= dryPrice;

								printf("Dispensing Canada Dry");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf(".");
								Sleep(375);
								printf("Enjoy!");
								Sleep(1000);
							}
							else
							{
								printf("Please Insert $%.2f More to Purchase the Item. (Press Any Key to Continue)\n", (dryPrice - money));
								getch();
							}
							break;
						}
						/////////////////////INVALID ENTRY HANDLING/////////////////////
						case '6':
						{
							loopFlag = 0;
							break;
						}
						default:
						{
							printf("Invalid Selection; Please Choose Again. (Press Any Key to Continue)\n");
							getch();
							break;
						}
					}
				}
				break;
			}
			///////////////////////////////////////////////////////////////////////////
			//////////////////////INVALID ENTRY HANDLING///////////////////////////////
			default:
			{
				printf("Invalid Selection; Please Choose Again. (Press Any Key to Continue)\n");
				getch();
				break;
			}
		}
	}
}