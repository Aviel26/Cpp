#pragma once
#include<iostream>
using namespace std;

class Account
{
private:
	int accountNumber;
	int code;
	float balance;

public:

	Account() { //default fconstructor
		accountNumber = 0;
		code = 0;
		balance = 0;
	}

	Account(int myAccount, int myCode, float myBalance) { //constructor with defaults parameters
		accountNumber = myAccount;
		balance = myBalance;
		try {
			if (myCode >= 1000 && myCode < 10000) {

				code = myCode;
			}
			else {
				throw "ERROR: code must be of 4 digits!";
			}
		}
			catch (const char*str)
		{
			cout << str;
		}
	}
	
	void setBalance(float);
	int getAccountNumber();
	float getBalance();
	int getCode();

	friend istream&operator>>(istream&, Account&);// redefin display with account parameters     
	void withdraw(int);
	void deposit(int);
	static float sumWithdraw;
	static float sumDeposit;
	static float getSumWithdraw() { return sumWithdraw; }//will not get earased at the end of the func-its static
	static float getSumDeposit() { return sumDeposit; }
	~Account() {};
};

