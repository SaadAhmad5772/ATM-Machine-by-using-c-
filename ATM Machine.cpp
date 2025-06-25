#include<iostream>
using namespace std;

void cashwithdrawal(int &balance)
{
    int amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount <= balance) {
        balance -= amount;
        cout << "Please collect your cash.\n";
    } else {
        cout << "Insufficient balance.\n";
    }
}

void checkbalance(int balance)
{
    cout << "Your current balance is: Rs. " << balance << endl;
}

void cashdeposit(int &balance)
{
    int amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    balance += amount;
    cout << "Amount deposited successfully.\n";
}

void fundtransfer(int &from, int &to)
{
    int amount;
    cout << "Enter amount to transfer to your other account: ";
    cin >> amount;
    if (amount <= from) {
        from -= amount;
        to += amount;
        cout << "Transfer successful.\n";
    } else {
        cout << "Insufficient balance.\n";
    }
}

void miniStatement(double transactions[], int size)
{
    cout << "Last " << size << " transactions:\n";
    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ": " << transactions[i] << " Rs\n";
    }
}

void showintro()
{
    cout << "*********************************************" << endl;
    cout << "* Welcome to ATM Machine Management System  *" << endl;
    cout << "* Developed by :                            *" << endl;
    cout << "*               Saad Ahmad                  *" << endl;
    cout << "*               Abdullah Khan               *" << endl;
    cout << "*               Fayeez Imarn                *" << endl;
    cout << "*********************************************" << endl;
}

void showmenu()
{
    cout << "\nEnter your choice: " << endl;
    cout << "1 for Cash Withdrawal" << endl;
    cout << "2 for Balance Inquiry" << endl;
    cout << "3 for Cash Deposit" << endl;
    cout << "4 for Fund Transfer" << endl;
    cout << "5 for Mini Statement" << endl;
    cout << "6 for Ending Process" << endl;
}

void choice(int &balance, int &secondacc_balance, double transactions[], int size)
{
    int c;
    do {
        showmenu();
        cin >> c;

        switch (c)
        {
        case 1:
            cashwithdrawal(balance);
            break;
        case 2:
            checkbalance(balance);
            break;
        case 3:
            cashdeposit(balance);
            break;
        case 4:
            fundtransfer(balance, secondacc_balance);
            break;
        case 5:
            miniStatement(transactions, size);
            break;
        case 6:
            cout << "Thank you for using the ATM. Goodbye." << endl;
            break;
        default:
            cout << "Invalid entry! Please Try Again.\n";
        }
    } while (c != 6);
}

int main()
{
    int pin;
    int balance = 100000;
    int secondacc_balance = 50000;
    double transactions[5] = {-5000, -10000, 20000, -3000, -15000};

    showintro();

    cout << "Enter your pin: ";
    cin >> pin;

    if (pin != 1234)
    {
        cout << "Incorrect pin! Exiting........ " << endl;
        return 0;
    }

    choice(balance, secondacc_balance, transactions, 5);

    return 0;
}
