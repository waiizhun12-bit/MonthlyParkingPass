#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include "system.h"

using namespace std;

void viewStatus(int &step, string &currID) {        //  maybe need to replace currID to something can know who is the user now
   
    clearScreen();
    loadApplication();

    bool found = false;

    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "-                            APPLICATION STATUS                                         -" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(8)  << left << "App ID"
         << " | " << setw(10) << left << "Student ID"
         << " | " << setw(20) << left << "Student Name"
         << " | " << setw(8) << left << "Status"
         << " | " << setw(5)  << left << "Month"
         << " | " << setw(6)  << left << "Year"
         << " | " << setw(8)  << left << "Duration"
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < appCount; i++) {
        if (appList[i].studentID == currID) {
        found = true;
        
         cout << "| " << setw(8)  << left << appList[i].appID
                 << " | " << setw(10) << left << appList[i].studentID
                 << " | " << setw(20) << left << appList[i].studentName
                 << " | " << setw(10) << left << appList[i].status
                 << " | " << setw(5)  << left << appList[i].startMonth
                 << " | " << setw(6)  << left << appList[i].startYear
                 << " | " << setw(8)  << left << appList[i].duration
                 << " |" << endl;
        }
    }

    cout << "-------------------------------------------------------------------------------" << endl;

    if (!found) {
        cout << "No application record found for this student." << endl;
    } else {
        cout << "\nStatus meaning:" << endl;
        cout << "- PENDING  : Waiting for admin review" << endl;
        cout << "- APPROVED : Your application is approved, you may proceed to payment" << endl;
        cout << "- REJECTED : Your application was rejected" << endl;
    }

    cout << "\nPress Enter back to student menu...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}