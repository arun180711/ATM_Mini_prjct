#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
using namespace std;
class ATM {

private:
	string name;
	long int accnumber;
	int pin=0;
    long int amount = 0;
	long int tot = 0;
	int newPin=0;

public:
	void setvalue()
	{
		cout << "ENTER YOUR NAME           : ";
		cin >> name;
		cout << "ENTER YOUR ACCOUNT NUMBER : ";
		cin >> accnumber;
		cout << "ENTER YOUR PIN CODE       : ";
		cin >> pin;
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
	void changePin()
	{
	    cout << "ENTER THE NEW PIN  : ";
	    cin >> newPin;
	    pin = newPin;
	    cout << "THE PIN HAS BEEN CHANGED SUCCESSFULLY!!";
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

	int printDetails()
	{
	    unsigned int fileSeq;
        ifstream seqFileIn;
        ofstream seqFileOut;


        seqFileIn.open("sequeceFile.txt", ios::in);
        if (seqFileIn.is_open())
        {
            seqFileIn >> fileSeq;
            fileSeq++;
        }
        else
            fileSeq = 1;
        bool newDataAvailable = true;

        if (newDataAvailable) {
            ofstream afile;
            string fileName = name + "details"  + to_string(fileSeq) + ".txt";
            afile.open(fileName, ios::app);
            afile    << "NAME               : " << name << endl
                     << "ACCOUNT NUMBER     : " << accnumber << endl
                     << "PIN                : " << pin << endl
                     << "BALANCE AVAILABLE  : " << tot << fileSeq << "\n";
            afile.close();
        }
        seqFileOut.open("sequeceFile.txt", ios::out);
        seqFileOut << fileSeq;
        cout << "THE RECEIPT HAS BEEN SENT!!";
        _getch();
        return 0;
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
		cout << "\t2. UPDATE PIN\n";
		cout << "\t3. DEPOSIT MONEY\n";
		cout << "\t4. SHOW TOTAL BALANCE\n";
		cout << "\t5. WITHDRAW MONEY\n";
		cout << "\t6. USER DETAILS\n";
		cout << "\t7. CANCEL\n\n";
		cin >> choice;
        system("cls");
		switch (choice)
		{
		case 1:
			b.setvalue();
			break;
		case 2:
			b.changePin();
			break;
		case 3:
			b.deposit();
			break;
		case 4:
			b.showbal();
			break;
		case 5:
			b.withdrawl();
			break;
        case 6:
            b.printDetails();
			break;
        case 7:
            exit(1);
		default:
			cout << "\nInvalid choice\n";
		}
	}
}
