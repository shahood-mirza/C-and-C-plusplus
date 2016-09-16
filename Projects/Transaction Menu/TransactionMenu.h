#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MainMenu;

class TransactionMenu {
	private:
		int accountNum;
		int val;

		float amount;
		float balance;

		string tranName;
		
		MainMenu *theMainMenu;

	public:
		TransactionMenu(int accNum, MainMenu *theMenu);

		void set_balance(float val);
		float get_balance();
		int get_accNum();
		
		void deposit();
		void withdraw();
		void determine_balance();
};

