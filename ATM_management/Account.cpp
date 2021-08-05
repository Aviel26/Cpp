#include "Account.h"
#include<iostream>
#include<string>


using namespace std;

float Account::sumDeposit = 0;
float Account::sumWithdraw = 0;

void Account::setBalance(float theBalance) //set balance
{
	balance = theBalance;
}
int Account::getAccountNumber() { 
	return accountNumber; //get number account
}
int Account::getCode() { //get the code
	return code;
}
float Account::getBalance() { //get the balance
	return balance;
}

istream&operator>>(istream& is, Account &theAccount) {
		
	theAccount.balance = 0;
		is >> theAccount.accountNumber >> theAccount.code;

	return is;
		
}

void Account::withdraw(int outputMoney) {
	try {
		if ((balance - outputMoney) > -6000 && outputMoney <= 2500)//if -6000 can't withdraw because maximal minus
		{                                                          // if >2500 cant't withdraw because big too much withdraw
			balance -= outputMoney;
			sumWithdraw += outputMoney;
		}
		else
		{
			if ((balance - outputMoney) < -6000)
				throw "ERROR: cannot have less than -6000 NIS!";
			else if (outputMoney > 2500)
				throw "ERROR: cannot withdraw more than 2500 NIS!";
		}
		
	}
	catch (const char*messg) {
		cout << messg;
	}

}
void Account::deposit(int myDeposit) {
	try {
		if (myDeposit > 10000)
		{
			throw"ERROR: cannot deposit more than 10000 NIS! ";
		}
		else {
			balance += myDeposit;// add the deposit money
			sumDeposit += myDeposit;// add to the total deposit
		}
	}
	catch (const char*mssg) {
		cout << mssg;
	}
	
}


