# include "Account.h"
# include "bankAccount.h"
# include "stockAccount.h"
#include "windows.h"
#include <vector>
# include <iostream>
# include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>   
#include <time.h> 
#include <math.h>

using namespace std;

int main() {

    stockAccount d2;
	

	

    bool flag = true;
    int selection = 0;
    char test[256];
    string line;
    while (flag) {

        cout << "Please select an account to access" << endl
            << "\t1. Stock Portfolio Account" << endl
            << "\t2. Bank Account" << endl
            << "\t3. Exit" << endl
            << "\tYour selection: ";

        cin.getline(test, 256);
        cout << "[READ FROM EXAMPLE.TXT] = " << test << endl;
        selection = atoi(test);
        Sleep(1);




        switch (selection) {
               case 1:
                cout << "\n\tMAIN - INPUT  = 1" << endl;
                d2.menu();
                break; 
			   
			   case 2: 
                cout << "\n\tMAIN - INPUT  = 2" << endl;
                d2.bankMenu();
                break;
        
            case 3:
                cout << "\n\tMAIN - INPUT  = 3\n" << endl;
                flag = false;
                break;
            default:
                cout << "\n\tMAIN - INPUT  = default" << endl;
                break;
        }
    }

    return 0;
}