#pragma once
#include "stdafx.h"
#include "TransactionMenu.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MainMenu {
	private:
		int accountNum=-1;
		int thisAcc;
		int i=0;
		vector<TransactionMenu> tran;

	public:
		int addTransactionMenu(int accNum);
		MainMenu();
};

