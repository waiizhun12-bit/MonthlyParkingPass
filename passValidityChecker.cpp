#include <iostream>
#include <ctime>
#include <iomanip>
#include <limits>
#include "system.h"
using namespace std;

void passValidityChecker(int &step, string &currID){
    clearScreen();
    loadApplication();

    bool found = false;

    time_t t = time(NULL);
    tm *now = localtime(&t);
    int curMonth = now->tm_mon + 1;
    int curYear = now->tm_year + 1900;

    cout << "---------------------------------------------------------------------" << endl;
    cout << "-                      PASS  VALIDITY  CHECKER                      -" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < appCount; i++){
        if (appList[i].studentID == currID && appList[i].status == "APPROVED"){
            found = true;

            int expiryMonth = appList[i].startMonth + appList[i].duration - 1;
            int expiryYear = appList[i].startYear;

            while (expiryMonth > 12){
                expiryMonth -= 12;
                expiryYear++;
            }

            cout << "Application ID : " << appList[i].appID << endl;
            cout << "Student ID     : " << appList[i].studentID << endl;
            cout << "Student Name   : " << appList[i].studentName << endl;
            cout << "Start Month    : " << appList[i].startMonth << endl;
            cout << "Start Year     : " << appList[i].startYear << endl;
            cout << "Duration       : " << appList[i].duration << " month(s)" << endl;
            cout << "Expiry Month   : " << expiryMonth << endl;
            cout << "Expiry Year    : " << expiryYear << endl;

            if (expiryYear > curYear || (expiryYear == curYear && expiryMonth >= curMonth)){
                cout << "Pass Status    : VALID" << endl;
            } else {
                cout << "Pass Status    : EXPIRED" << endl;
            }

            cout << "---------------------------------------------------------------------" << endl;

        }
    }

    if (!found){
        cout << "No approved pass found for this student." << endl;
    }

    cout << "\nPress Enter back to student menu...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}