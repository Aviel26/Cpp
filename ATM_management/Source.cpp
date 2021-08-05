#include "Account.h"
#include"Clock.h"
enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)//checking if the acount actually exist
{
	int number, code;
	cout << "please enter account number: " << endl;
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)//looking for the account
		i++;
	if (i == 10 && bank[i - 1].getAccountNumber() != number)//if the account doesnt exsist
		return -1;
	cout << "please enter the code: " << endl;
	cin >> code;
	if (bank[i].getCode() == code)//is indeed the account
		return i;
	return -2;//wrong code
}
void printTransaction(Account a, action ac, Clock& c)//printing out the requested action
{
	if (ac != 4 && ac != 5)// if the action takes time
		cout << c << "\t";
	else
	{
		c += 60;
		cout << c << "\t";
	}
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)//getting the balance of the acount
{
	try {
		int i = findAccount(bank, size);//looking for the account
		if (i == -1)
			throw "ERROR: no such account number!";
		if (i == -2)
			throw "ERROR: wrong code!";
		c += 20;
		printTransaction(bank[i], balance, c);
	}
	catch (const char* str)//printing it out
	{
		cout << c << '\t' << str << endl;
		return;
	}
}
void cashDeposit(Account* bank, int size, Clock& c)//if the user wants to make a deposit
{
	try {
		int i = findAccount(bank, size);//looking for the acount
		if (i == -1)
			throw "ERROR: no such account number!";
		if (i == -2)
			throw "ERROR: wrong code!";
		float amount;
		cout << "enter the amount of the check: " << endl;
		cin >> amount;
		if (amount > 10000)
		{
			throw "ERROR: cannot deposit more than 10000 NIS!";
			printTransaction(bank[i], deposit, c);
		}
		else {
			bank[i].deposit(amount);//making the deposit
			c += 30;
			printTransaction(bank[i], deposit, c);
		}
	}
	catch (const char* str)
	{
		cout << c << '\t' << str << endl;
	}
}
void cashWithdraw(Account* bank, int size, Clock& c)//withdraw of money
{
	try {
		int i = findAccount(bank, size);//looking for the acount
		if (i == -1)
			throw "ERROR: no such account number!";
		if (i == -2)
			throw "ERROR: wrong code!";
		float amount;
		cout << "enter the amount of money to withdraw: ";
		cin >> amount;
		if ((bank[i].getBalance() - amount) < -6000)
		{
			throw "ERROR: cannot have less than -6000 NIS!";
		}
		else if (amount > 2500)
		{
			throw "ERROR: cannot withdraw more than 2500 NIS!";
			printTransaction(bank[i], withdraw, c);
		}
		else {
			bank[i].withdraw(amount);//making the withdraw
			c += 50;
			printTransaction(bank[i], withdraw, c);
		}
	}
	catch (const char* str)
	{
		cout << c << '\t' << str << endl;
	}
}
int main()
{
	Clock c(8);
	Account bank[10];
	cout << "enter account number and code for 10 accounts:\n";
	for (int i = 0; i < 10; i++)
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
			{
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
				if (bank[i].getCode() < 1000 || bank[i].getCode() > 9999) // if the code not 1000...1001....10002....99998
				{
					throw "ERROR: code must be of 4 digits!";

				}
			}
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg << endl;
			i--;
		}
	}
	action ac = menu();
	while (ac)
	{
		switch (ac)
		{
		case balance: getBalance(bank, 10, c);
			break;
		case withdraw:cashWithdraw(bank, 10, c);
			break;
		case deposit:cashDeposit(bank, 10, c);
			break;
		case sumDeposit:
			printTransaction(bank[0], sumDeposit, c);
			break;
		case sumWithdraw:
			printTransaction(bank[0], sumWithdraw, c);

		}
		ac = menu();
	}
	return 0;
}