#include <iostream>
#include <ctime>
#include "system.h"

using namespace std;

void monthlyAlertStudent (int &step, string &currStudentID){
        clearScreen();
        loadApplication();

        time_t t = time(NULL);                   // Get the current time (in second)
        tm *now = localtime(&t);                 // Convert time to date
        int curMonth = now-> tm_mon + 1;        
        int curYear = now-> tm_year + 1900;

        bool found = false;

        for (int i = 0; i < appCount; i++){
            
            if (appList[i].studentID == currStudentID && appList[i].status == "APPROVED"){

                int expireMonth = appList[i].startMonth + appList[i].duration - 1;
                int expireYear = appList[i].startYear;

                while (expireMonth > 12){
                    expireMonth -= 12;
                    expireYear++;
                }

                if (expireMonth == curMonth && expireYear == curYear){
                    cout << "---------------------------------------------------------------\n" << endl;
                    cout << "-             MONTH      END      RENEWAL      ALERT          -\n" << endl;
                    cout << "---------------------------------------------------------------\n" << endl;
                    cout << "Reminder: Your parking pass is expiring this month.\n";
                    cout << "Student ID     : " << appList[i].studentID << endl;
                    cout << "Student Name   : " << appList[i].studentName << endl;
                    cout << "Expiry Month   : " << expireMonth << " / " << expireYear << endl;
                    cout << "---------------------------------------------------------------\n" << endl;

                    found = true;
                    break;
                }   
            }
        }

        if (!found){
            cout << "No month-end renewal alert for this student.\n";
            return;
        }

        cout << "Back to Student Menu.\n";
        step = 3; 
        return;

        clearScreen();
}