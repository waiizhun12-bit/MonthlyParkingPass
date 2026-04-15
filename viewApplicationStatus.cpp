#include <iostream>
#include <limits>
#include <iomanip>
#include "system.h"

using namespace std;

void viewStatus(int &step, string &currID) {        //  maybe need to replace currID to something can know who is the user now
    clearScreen();
    loadApplication();

    bool found = false;

    for (int i = 0; i < appCount; i++) {
        if (appList[i].studentID == currID) {
            found = true;
    cout << "------------------------------------------------------" << endl;
    cout << "-             APPLICATION     STATUS                 -" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "- App ID: " << appList[i].appID                  << "-" << endl;
    cout << "- Student ID: " << appList[i].studentID          << "-" << endl;
    cout << "- Student Name: " << appList[i].studentName      << "-" << endl;
    cout << "- Status: " << appList[i].status                 << "-" << endl;
    cout << "- Month: " << appList[i].startMonth              << "-" << endl;
    cout << "- Year: " << appList[i].startYear                << "-" << endl;
    cout << "- Duration: " << appList[i].duration             << "-" << endl;
    cout << "-----------------------------------------------------" << endl;
        }
    }

    if (!found) {
        cout << "No application record found for this student." << endl;
    } else {
        cout << "\nStatus meaning:" << endl;
        cout << "- PENDING  : Waiting for admin review" << endl;
        cout << "- APPROVED : Your application is approved, you may proceed to payment" << endl;
        cout << "- REJECTED : Your application was rejected" << endl;
    }

    cout << "\nPress Enter back to student menu...";
    cin.ignore(std :: numeric_limits<stringstream>:: max(), '\n');
    cin.get();
}