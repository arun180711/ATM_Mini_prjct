#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
using namespace std;
class ATM {

private:
	string name;
	long int accnumber;
    long int amount = 0;
	long int tot = 0;

public:
	void setvalue()
	{
		cout << "ENTER YOUR NAME           : ";
		cin >> name;
		cout << "ENTER YOUR ACCOUNT NUMBER : ";
		cin >> accnumber;
		cout << "ENTER BALANCE             : ";
		cin >> tot;
		_getch();
	}

	void deposit()
	{
		cout << "\nENTER AMOUNT TO BE DEPOSITED : \n";
		cin >> amount;
		_getch();
	}

	void showbal()
	{
		tot +=  amount;
		cout << "\nTOTAL BALANCE IS : " << tot;
		_getch();
	}

	void withdrawl()
	{
		int a;
		cout << "ENTER AMOUNT TO WITHDRAW : \n";
		cin >> a;
		if( a > 0 && a < tot )
        {
            tot -= a;
            cout << "AVAILABLE BALANCE IS : " << tot;
        }
        else
        {
            cout << "INSUFFICIENT BALANCE...";
        }
		_getch();
	}

	void printDetails()
	{
	    cout << endl << "NAME               : " << name;
	    cout << endl << "ACCOUNT NUMBER     : " << accnumber;
	    cout << endl << "BALANCE AVAILABLE  : " << tot;
	    _getch();
	}
};
int main()
{

	ATM b;
	int choice;
	while (1){
        system("cls");
		cout << "ENTER YOUR CHOICE : \n\n";
		cout << "\t1. ENTER THE DETAILS\n";
		cout << "\t2. DEPOSIT MONEY\n";
		cout << "\t3. SHOW TOTAL BALANCE\n";
		cout << "\t4. WITHDRAW MONEY\n";
		cout << "\t5. USER DETAILS\n";
		cout << "\t6. CANCEL\n\n";
		cin >> choice;
        system("cls");
		switch (choice)
		{
		case 1:
			b.setvalue();
			break;
		case 2:
			b.deposit();
			break;
		case 3:
			b.showbal();
			break;
		case 4:
			b.withdrawl();
			break;
		case 5:
			b.printDetails();
			break;
        case 6:
            exit(1);
		default:
			cout << "\nInvalid choice\n";
		}
	}
}
