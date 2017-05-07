# ifndef BANKACCOUNT_H
# define BANKACCOUNT_H

#include <windows.h>
# include <iostream>

using namespace std;

class bankAccount: public Account {
public:
	bankAccount();
	void bankMenu();
	void deposit(double);
	void withdraw(double);
	double validInput(double x, bool y);
	void bankTrans();
	void displayPortfolio2();
	double randPrice2(string);
	void createStock2();
	string timing();
	string getDate();
private:

};
# endif

bankAccount::bankAccount() {
	cout << "MAKING DERIVE 1" << endl;
}

void bankAccount::bankMenu() {
	bool flag = true;
	int selection;
	char test[256];
	while (flag) {
		cout << "\nPlease select an option" << endl
			<< "\t1. View account balance" << endl
			<< "\t2. Deposit money" << endl
			<< "\t3. Withdraw money" << endl
			<< "\t4. Display transaction history" << endl
			<< "\t5. Return to previous menu" << endl;

		cout << "\tYour selection: ";

		cin.getline(test, 256);
		cout << "[READ FROM EXAMPLE.TXT] = " << test << endl;
        selection = atoi(test);
        Sleep(1);



		switch(selection) {
			case 1:
				cout << "\n\tDERIVE 1 - INPUT = 1" << endl;
				cout<<getBalance();
				break;
			case 2: {
				char line[256];
				double amount;
				cout << "\n\tDERIVE 1 - INPUT = 2" << endl;
				cin.getline(line, 256);
				cout << "\t[READ FROM EXAMPLE.TXT] = " << line << endl;
				amount = stod(line);
				amount=validInput(amount, 0);
				deposit(amount);
				break;
			}
			case 3: {
				char line[256];
				double amount;
				cout << "\n\tDERIVE 1 - INPUT = 3" << endl;
				cin.getline(line, 256);
				cout << "\t[READ FROM EXAMPLE.TXT] = " << line << endl;
				amount = stod(line);
				amount = validInput(amount, 1);
				withdraw(amount);
				break;
			}
			case 4:
				cout << "\n\tDERIVE 1 - INPUT = 4" << endl;
				bankTrans();
				break;
			case 5:
				cout << "\n\tDERIVE 1 - INPUT = 5\n" << endl;
				flag = false;
				break;
			default:
				cout << "\n\tDERIVE 1 - INPUT = default" << endl;
				break;
		}
	}
}

void bankAccount::deposit(double val) {
	cout << "\tCALLING DEPOSIT FUNCTION\t\t AMOUNT = " << val << endl;
	cout << endl << "Deposit $" << val << " to bank account"<<endl<<endl;
	setBalance(getBalance() + val);
	string line2 = "Deposit\t\t" + to_string(val) + "\t" + to_string(getBalance()) + "\t" + getDate() + "\t" + timing();
	ofstream myfile2;
	myfile2.open("bank_transaction_history.txt", ios_base::app);
	myfile2 << line2 << endl;
	myfile2.close();
	displayPortfolio2();
	Sleep(1);
}

void bankAccount::withdraw(double val) {
	cout << "\tCALLING WITHDRAW FUNCTION\t\t AMOUNT = " << val << endl;
	cout << endl << "Withdraw $" << val << " to bank account" << endl << endl;
	string line2 = "Withdraw\t" + to_string(val) + "\t" + to_string(getBalance()) + "\t" + getDate() + "\t" + timing();
	ofstream myfile2;
	myfile2.open("bank_transaction_history.txt", ios_base::app);
	myfile2 << line2 << endl;
	myfile2.close();
	setBalance(getBalance() - val);
	displayPortfolio2();
    Sleep(1);
}

double bankAccount::validInput(double x, bool y) {
begin:



	if (x < 0) {
		cout << "Please enter a positive number: ";
		cin >> x;
		goto begin;
	}

	if (y) {

		if ((getBalance() - x) < 0) {
			cout << "Insufficient funds. Enter a valid withdrawl amount: " << endl;
			cin >> x;
			goto begin;

		}
	}
	return x;

}

void bankAccount::bankTrans() {
	cout << "Action\t\tAmount\t\tCash Balance\tDate\t\tTime" << endl;
	ifstream file("bank_transaction_history.txt");
	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}
	file.close();

}


void bankAccount::displayPortfolio2() {
	createStock2();
	cout << "Cash Balance = $" << getBalance() << endl << endl;
	cout << "Symbol\tCompany\t\t\t\t\Number\tPrice\tTotal" << endl;
	int pricing = 0;
	double total = getBalance();
	for (int i = 0; i < glob; i++) {
		pricing = randPrice2(currentList[i].symbol);
		cout << currentList[i].symbol << "\t" << currentList[i].company << "\t\t" << currentList[i].shares << "\t" << pricing << "\t" << pricing*currentList[i].shares << endl;
		total += pricing*currentList[i].shares;
	}
	cout << endl;
	cout << "Total portfolio value: $ " << total << endl;

}

double bankAccount::randPrice2(string sym) {
	int index = 0;
	createStock2();
	for (int j = 0; j < 35; j++) {
		if (stock[j].symbol == sym) {
			index = j;
			break;
		}
	}
	return stock[index].price;
}

void bankAccount::createStock2() {
	srand(time(0));

	stock.clear();
	int num = rand() % 4 + 1;
	string name = "stock" + to_string(num) + ".txt";
	ifstream file(name);
	string line1;
	vector <string> tokens;
	while (getline(file, line1))
	{
		string delim = "\t";

		for (int i = 0; i < 3; i++) // making 3 tokens
		{
			if (i == 2) { // handling newline character
				line1 = line1.substr(line1.rfind(delim) + 1, string::npos);

			}
			tokens.push_back(line1.substr(0, line1.find(delim)));
			line1 = line1.substr(line1.find(delim) + 1, string::npos);
		}
	}
	file.close();

	for (int i = 0; i < 35; i++) {
		stock.push_back({ tokens[3 * i],tokens[3 * i + 1],0,stod(tokens[3 * i + 2]) });
	}
}

string bankAccount::getDate() {

	string all;
	time_t t = time(0);
	struct tm * now = localtime(&t);

	all = to_string(now->tm_mon + 1) + "/" + to_string(now->tm_mday) + "/" + to_string(now->tm_year + 1900);

	return all;
}

string bankAccount::timing() {

	time_t timer;
	struct tm y2k = { 0 };
	double seconds;

	y2k.tm_hour = 0;
	y2k.tm_min = 0;
	y2k.tm_sec = 0;
	y2k.tm_year = 100;
	y2k.tm_mon = 0;
	y2k.tm_mday = 1;

	time(&timer);

	seconds = difftime(timer, mktime(&y2k));
	int tot_seconds_today = remainder(seconds, 86400);
	if (tot_seconds_today < 0) {
		tot_seconds_today += 86400;
	}
	int hours_today = floor(tot_seconds_today / 3600);
	int minutes_today = floor((tot_seconds_today - hours_today * 3600) / 60);
	int seconds_today = (tot_seconds_today - hours_today * 3600 - minutes_today * 60);
	string out = to_string(hours_today + 1) + ":" + to_string(minutes_today) + ":" + to_string(seconds_today);
	return out;


}