#include "stdafx.h"
#include "TransactionMenu.h"


TransactionMenu::TransactionMenu(int accNum, MainMenu *theMenu)
{
	accountNum = accNum;
	theMainMenu = theMenu;
}

void TransactionMenu::set_balance(float val) {
	balance = val;
}

float TransactionMenu::get_balance() {
	return balance;
}

int TransactionMenu::get_accNum(){
	return accountNum;
}

void TransactionMenu::deposit() {
	cout << "Deposit \n";
	cout << "Account Number: " << this->get_accNum() << "\n";
	cout << "Balance: $" << this->get_balance() << "\n\n";

	cout << "Enter deposit amount: $";
	cin >> val;
	balance += val;
	cout << "New Balance: $" << this->get_balance() << "\n\n";

	system("pause");
	system("cls");
}

void TransactionMenu::withdraw() {
	cout << "Withdraw \n";
	cout << "Account Number: " << this->get_accNum() << "\n";
	cout << "Balance: $" << this->get_balance() << "\n\n";

	cout << "Enter withdraw amount: $";
	cin >> val;
	if ((balance-val) >= 0) {
		balance -= val;
		cout << "New Balance: $" << this->get_balance() << "\n\n";
	}
	else
		cout << "Not Enough Funds! \n\n";

	system("pause");
	system("cls");
}

void TransactionMenu::determine_balance() {
	cout << "Determine Balance \n\n";
	cout << "Account Number: " << this->get_accNum() << "\n";
	cout << "Balance: $" << this->get_balance() << "\n\n";

	system("pause");
	system("cls");
}