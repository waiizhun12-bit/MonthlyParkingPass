#include <iostream>
#include <ctime>
#include <limits>
#include "system.h"
using namespace std;

void monthEndAlertStudent(string &currID){
    clearScreen();
    loadApplication();

    time_t t = time(NULL);
    tm *now = localtime(&t);
    int currentMonth = now->tm_mon + 1;
    int currentYear = now->tm_year + 1900;

    bool found = false;

    cout << "--------------------------------------------------------------------" << endl;
    cout << "-                        MONTH   END   ALERT                       -" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    for (int i = 0; i < appCount; i++){

        if (appList[i].studentID == currID && appList[i].status == "APPROVED"){

            int validMonth = appList[i].startMonth + (appList[i].duration - 1);
            int validYear = appList[i].startYear;

            while (validMonth > 12){
                validMonth -= 12;
                validYear++;
            }

            bool expiringThisMonth =
                (currentYear == validYear && currentMonth == validMonth);

            bool alreadyExpired =
                (currentYear > validYear) ||
                (currentYear == validYear && currentMonth > validMonth);

            if (expiringThisMonth){
                found = true;
                cout << "Reminder: Your parking pass is expiring this month.\n";
                cout << "Please renew for next month.\n";
                cout << "Student ID   : " << appList[i].studentID << endl;
                cout << "Student Name : " << appList[i].studentName << endl;
                cout << "Expiry Month : " << validMonth << "/" << validYear << endl;
                cout << "--------------------------------------------------------------------" << endl; 
            }
            else if (alreadyExpired){
                found = true;
                cout << "Your parking pass has already expired.\n";
                cout << "Please apply / renew your pass." << endl;
                cout << "Student ID   : " << appList[i].studentID << endl;
                cout << "Student Name : " << appList[i].studentName << endl;
                cout << "Expiry Month : " << validMonth << "/" << validYear << endl;
                cout << "-------------------------------------------------\n";
            }
        }
    }

    if (!found){
        cout << "No month-end alert for this student.\n";
    }

    cout << "\nPress Enter to continue...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}