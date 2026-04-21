#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <ctime>
#include "system.h"

using namespace std;

void makePayment(int &step, string &currID, string &name, string &vehicleNo,
                 int startMonth, int startYear, int duration)
{
    clearScreen();
    loadApplication();
    loadPayment();

    /* logic is, when admin approved, then student can pay. 
       Below loop is for checking is this student application being approved? */

    bool approvedFound = false;

    for (int i = 0; i < appCount; i++)
    {
        if (appList[i].studentID == currID && appList[i].status == "APPROVED")
        {
            approvedFound = true;
            name = appList[i].studentName;
            vehicleNo = appList[i].vehicleNo;
            startMonth = appList[i].startMonth;
            startYear = appList[i].startYear;
            duration = appList[i].duration;
            break;
        }
    }

    if (!approvedFound)
    {
        cout << "You do not have any approved application to make payment." << endl;
        cout << "Press Enter back to student menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    double total = duration * 50;
    int payChoice;
    string payMethod = "";

    cout << "---------------------------------------------------------------------" << endl;
    cout << "-                           PAYMENT PAGE                            -" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Month: " << startMonth << endl;
    cout << "Vehicle Number: " << vehicleNo << endl;
    cout << "Year: " << startYear << endl;
    cout << "Duration: " << duration << endl;
    cout << "Total: RM " << total << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "Select payment method: " << endl;
    cout << "1. Online Banking" << endl;
    cout << "2. Touch 'n Go" << endl;
    cout << "3. Debit / Credit Card" << endl;
    cout << "0. Cancel Payment" << endl;
    cout << "Enter your choice: ";
    cin >> payChoice;

    switch (payChoice)
    {
        case 1:
            payMethod = "ONLINE BANKING";
            break;
        case 2:
            payMethod = "TOUCH N GO";
            break;
        case 3:
            payMethod = "CARD";
            break;
        case 0:
            cout << "Payment cancelled." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return;
        default:
            invalid();
            return;
    }

    time_t now = time(NULL);
    tm *local = localtime(&now);

    // Get trhe current date
    string date = toString(1900 + local->tm_year) + "-" +
                  (local->tm_mon + 1 < 10 ? "0" : "") + toString(local->tm_mon + 1) + "-" +
                  (local->tm_mday < 10 ? "0" : "") + toString(local->tm_mday);

    payNo++;
    payList[payCount].paymentID = "P" + toString(payNo);
    payList[payCount].studentID = currID;
    payList[payCount].paymentStatus = "PENDING";
    payList[payCount].amount = total;
    payList[payCount].paymentDate = date;
    payCount++;

    savePayment();

    cout << "Payment submitted successfully." << endl;
    cout << "Waiting for admin verification." << endl;
    cout << "Press Enter...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}