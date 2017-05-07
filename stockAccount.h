# ifndef STOCKACCOUNT_H
# define STOCKACCOUNT_H
//right

#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h> 

using namespace std;

class stockAccount: public bankAccount {
public:
	stockAccount();
	void menu();
	void stockPrice(string);
	void buyStock(string, int, double);
	void sellStock(string, int, double);
	void createStock();
	//string timing();
	//string getDate();
	void displayPortfolio();
	double randPrice(string);
	void dispTran();
private:

	int numOfStock;

};
# endif


stockAccount::stockAccount() {
	cout << "MAKING DERIVE 2" << endl;
	numOfStock = 0;
}

void stockAccount::menu() {
	bool flag = true;
	int selection = 0;
	char test[256];

	while (flag) {
		cout << "\nPlease select an option" << endl
			<< "\t1. Display current price for a stock symbol" << endl
			<< "\t2. Buy stock" << endl
			<< "\t3. Sell stock" << endl
			<< "\t4. Display current portfolio" << endl
			<< "\t5. Display transaction history" << endl
			<< "\t6. Return to previous menu" << endl;

		cout << "\tYour selection: ";

		cin.getline(test, 256);
		cout << "[READ FROM EXAMPLE.TXT] = " << test << endl;
        selection = atoi(test);
        Sleep(1);



		switch(selection) {
			case 1: {
				cout << "\n\tDERIVE 2 - INPUT = 1" << endl;
				char line[256];
				cin.getline(line, 256);
				cout << "\t[READ FROM EXAMPLE.TXT] = " << line << endl;
				string symbol(line); // CONVERT TO STRING SO YOU CAN USE THE CODE SNIPPET IN THE PREVIOUS INSTRUCTION
				stockPrice(symbol);
				break;
			}
			case 2: {
				cout << "\n\tDERIVE 2 - INPUT = 2" << endl;
				char line[256];
				cin.getline(line, 256);
				cout << "\t[READ FROM EXAMPLE.TXT] = " << line << endl;
				string symbol(line); // CONVERT TO STRING SO YOU CAN USE THE CODE SNIPPET IN THE PREVIOUS INSTRUCTION
				
				
				vector <string> tokens;

				char delim = ' ';

				for (int i = 0; i < 3; i++) // making 3 tokens
				{
					if (i == 2) { // handling newline character
						symbol = symbol.substr(symbol.rfind(delim) + 1, string::npos);

					}
					tokens.push_back(symbol.substr(0, symbol.find(delim)));
					symbol = symbol.substr(symbol.find(delim) + 1, string::npos);
				}


				/*

				USE THE PREVIOUS INSTRUCTION TO PARTITION THE STRING INTO MULTIPLE TOKENS
				THEN PASS THE TOKENS TO THE FUNCTION BELOW;

				I WILL PUT IN SOME PARAMETERS IN THIS EXAMPLE SO THE FUNCTION CAN RUN;

				*/
				symbol = tokens[0];
				int numShare = stoi(tokens[1]);
				double price = stod(tokens[2]);

				buyStock(symbol, numShare, price);
				break;
			}
			case 3: {
				cout << "\n\tDERIVE 2 - INPUT = 3" << endl;
				char line[256];
				cin.getline(line, 256);
				cout << "\t[READ FROM EXAMPLE.TXT] = " << line << endl;
				string symbol(line); // CONVERT TO STRING SO YOU CAN USE THE CODE SNIPPET IN THE PREVIOUS INSTRUCTION
				
				vector <string> tokens;

				char delim = ' ';

				for (int i = 0; i < 3; i++) // making 3 tokens
				{
					if (i == 2) { // handling newline character
						symbol = symbol.substr(symbol.rfind(delim) + 1, string::npos);

					}
					tokens.push_back(symbol.substr(0, symbol.find(delim)));
					symbol = symbol.substr(symbol.find(delim) + 1, string::npos);
				}


				/*

				USE THE PREVIOUS INSTRUCTION TO PARTITION THE STRING INTO MULTIPLE TOKENS
				THEN PASS THE TOKENS TO THE FUNCTION BELOW;

				I WILL PUT IN SOME PARAMETERS IN THIS EXAMPLE SO THE FUNCTION CAN RUN;

				*/
				symbol = tokens[0];
				int numShare = stoi(tokens[1]);
				double price = stod(tokens[2]);

				sellStock(symbol, numShare, price);
				break;
			}
			case 4:
				cout << "\n\tDERIVE 2 - INPUT = 4" << endl;
				displayPortfolio();
				break;
			case 5:
				cout << "\n\tDERIVE 2 - INPUT = 5" << endl;
				dispTran();
				break;
			case 6:
				cout << "\n\tDERIVE 2 - INPUT = 6\n" << endl;
				flag = false;
				break;
			default:
				cout << "\n\tDERIVE 2 - INPUT = default" << endl;
				break;
		}
	}
}

void stockAccount::stockPrice(string symbol) {
	cout << "\tCALLING STOCKPRICE FUNCTION\t\tSYMBOL = " << symbol << endl;

	createStock();
	bool b = 1;
	for (int j = 0; j < 35; j++) {
		if (stock[j].symbol == symbol) {
			cout << stock[j].symbol <<"\t\t" << stock[j].company <<"\t\t" << stock[j].price <<"\t\t"<< timing()<<endl;
			b = 0;
			break;
		}
	}
	if (b) {
		cout << endl;
		cout << "Symbol not found" << endl;
	}
    Sleep(1);
}

void stockAccount::buyStock(string symbol, int numShare, double price) {
	cout << "\tCALLING BUYSTOCK FUNCTION\t\tSYMBOL = " << symbol
		<< "\tSHARE = " << numShare << "\tPRICE = " << price << endl;
	int index = 0;
	bool check2=0;
	int index2 = 0;
	createStock();
	bool check = 0;
	for (int j = 0; j < 35; j++) {
		if (stock[j].symbol == symbol) {
			index = j;
			check = 1;
			break;
		}
	}
	if (price < stock[index].price || (price*numShare)>getBalance() || !check) {
		cout << "Cannot process transaction" << endl;
	}
	else {
		
		string line = "Buy\t" + symbol + "\t" + to_string(numShare) + "\t" + to_string(stock[index].price) + "\t" + timing();
		ofstream myfile;
		myfile.open("stock_transaction_history.txt", ios_base::app);
		myfile << line << endl;
		myfile.close();

		for (int j = 0; j < numOfStock; j++) { 
			if (currentList[j].symbol == symbol) {
				index2 = j;
				check2 = 1;
				break;
			}
		}
		if (check2) {
			currentList[index2].shares += numShare;
		}
		else {
			currentList.push_back({ stock[index].symbol,stock[index].company,numShare,0 });
			numOfStock++;
			glob = numOfStock;
		}

		withdraw(stock[index].price*numShare);

		string line2 = "Withdraw\t" + to_string(stock[index].price*numShare) + "\t" + to_string(getBalance()) + "\t" + getDate() + "\t" + timing();
		ofstream myfile2;
		myfile2.open("bank_transaction_history.txt", ios_base::app);
		myfile2 << line2 << endl;
		myfile2.close();

	}

		Sleep(1);
	}


void stockAccount::sellStock(string symbol, int numShare, double price) {
	cout << "\tCALLING SELLSTOCK FUNCTION\t\tSYMBOL = " << symbol
		<< "\tSHARE = " << numShare << "\tPRICE = " << price << endl;
	
	int index = 0;
	int index2 = 0;
	bool check = 0;
	createStock();
	for (int j = 0; j < numOfStock; j++) { 
		if (currentList[j].symbol == symbol) {
			index = j;
			check = 1;
			break;
		}
	}

	for(int j = 0; j < 35; j++){
		if (stock[j].symbol == symbol) {
				index2 = j;
				break;
			}

		if (!check) {
			goto block;
		}
	}
		if (price > stock[index2].price || numShare > currentList[index].shares) {
		block:
			cout << "Cannot process transaction" << endl;
		}
		else {
			
			string line = "Sell\t" + symbol + "\t" + to_string(numShare) + "\t" + to_string(stock[index2].price) + "\t" + timing();
			ofstream myfile;
			myfile.open("stock_transaction_history.txt", ios_base::app);
			myfile << line << endl;
			myfile.close();
			if (currentList[index].shares == numShare) {
				currentList.erase(currentList.begin() + index);
				numOfStock--;
				glob = numOfStock;
			}
			else {
				currentList[index].shares -= numShare;
			}
			deposit(stock[index2].price*numShare);
			string line2 = "Deposit\t\t" + to_string(stock[index2].price*numShare) + "\t" + to_string(getBalance()) + "\t" + getDate() + "\t" + timing();
			ofstream myfile2;
			myfile2.open("bank_transaction_history.txt", ios_base::app);
			myfile2 << line2 << endl;
			myfile2.close();
		
		}
		
		Sleep(1);
}

void stockAccount::createStock() {
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

		for (int i = 0; i < 3; i++)
		{
			if (i == 2) { 
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



void stockAccount::displayPortfolio() {
	createStock();
	cout << "Cash Balance = $" << getBalance()<<endl<<endl;
	cout << "Symbol\tCompany\t\t\t\t\Number\tPrice\tTotal"<<endl;
	double pricing = 0.00;
	double total = getBalance();
	for (int i = 0; i < numOfStock; i++) {
		pricing = randPrice(currentList[i].symbol);
		cout << currentList[i].symbol << "\t" << currentList[i].company << "\t\t" << currentList[i].shares << "\t" << pricing << "\t" << pricing*currentList[i].shares<<endl;
		total += pricing*currentList[i].shares;
	}
	cout << endl;
	cout << "Total portfolio value: $ " << total<<endl;

}

double stockAccount::randPrice(string sym) {
	int index=0;
	createStock();
	for (int j = 0; j < 35; j++) {
		if (stock[j].symbol == sym) {
			index = j;
			break;
		}
	}
	return stock[index].price;
}

void stockAccount::dispTran() {

	cout << "Action\tSymbol\tShares\tPrice\t\tTime"<<endl;
		ifstream file("stock_transaction_history.txt");
		string line;
		while (getline(file, line))
		{
			cout << line << endl;
		}
		file.close();
}