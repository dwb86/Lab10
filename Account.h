

# ifndef ACCOUNT_H
# define ACCOUNT_H
#include <iostream>
#include <windows.h>
#include <vector>
# include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
# include <iostream>
#include <math.h>
#include <time.h> 
using namespace std;

class Account {
public:

	Account();
	double getBalance();
	void setBalance(double);
	virtual void menu()=0;
	

private:

	double cashBalance=10000;

protected:

	struct Stock {
		string symbol;
		string company;
		int shares;
		double price;
	};

	vector <Stock> stock;
	vector <Stock> currentList;
	int glob = 0;

};
# endif
Account::Account() {
	cout << "MAKING BASE" << endl;
}

void Account::setBalance(double cash) {
	cashBalance = cash;
}

double Account::getBalance() {
	return cashBalance;
}

