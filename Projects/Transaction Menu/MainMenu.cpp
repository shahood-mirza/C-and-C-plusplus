#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MainMenu() {
	while (accountNum != 0) {
		i = 0;

		cout << "Enter Your Account Number (0 to exit): \n";
		cin >> accountNum;

		thisAcc = addTransactionMenu(accountNum);

		system("cls");

		while (i != 4 && accountNum != 0) {
			cout << "Account Number: " << accountNum << "\n\n";
			cout << "Welcome! What Would You Like to Do? \n\n";
			cout << "1. Deposit \n";
			cout << "2. Withdrawal \n";
			cout << "3. Determine Balance \n";
			cout << "4. Exit \n\n";

			cin >> i;

			switch (i) {
			case 1:
				system("cls");
				tran[thisAcc].deposit();
				break;
			case 2:
				system("cls");
				tran[thisAcc].withdraw();
				break;
			case 3:
				system("cls");
				tran[thisAcc].determine_balance();
				break;
			case 4:
				break;
			default:
				cout << "Unknown Entry \n\n";
				system("pause");
				system("cls");
				break;
			}
		}
		system("cls");
	}
	cout << "Thank You!\n";
	system("pause");
	system("cls");
}

int MainMenu::addTransactionMenu(int accNum) {
	TransactionMenu newTranMenu = TransactionMenu(accNum, this);
	tran.push_back(newTranMenu);

	return tran.size() - 1;
}
