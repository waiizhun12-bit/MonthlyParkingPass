#include <iostream>
#include <iomanip>
#include <limits>
#include "system.h"
using namespace std;

void viewTransactionHistory(int &step, string &currID){
    clearScreen();
    loadPayment();

    bool found = false;

    cout << "--------------------------------------------------------------------" << endl;
    cout << "-                   VIEW    TRANSACTION   HISTORY                  -" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    cout << "| " << setw(10) << left << "Payment ID"
         << " | " << setw(10) << left << "Student ID"
         << " | " << setw(12) << left << "Status"
         << " | " << setw(8)  << left << "Amount"
         << " | " << setw(12) << left << "Date"
         << " |" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    for (int i = 0; i < payCount; i++){
        if (payList[i].studentID == currID){
            found = true;

            cout << "| " << setw(10) << left << payList[i].paymentID
                 << " | " << setw(10) << left << payList[i].studentID
                 << " | " << setw(12) << left << payList[i].paymentStatus
                 << " | " << setw(8)  << left << payList[i].amount
                 << " | " << setw(12) << left << payList[i].paymentDate
                 << " |" << endl;
        }
    }

    cout << "--------------------------------------------------------------------" << endl;

    if (!found){
        cout << "No transaction history found for this student." << endl;
    }

    cout << "\nPress Enter back to student menu...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}