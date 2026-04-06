#include <iostream>
#include <iomanip>
#include <ctime>
#include "system.h"
using namespace std;


void monthEndAlter(int &step){

    loadApplication();

    time_t t = time(nullptr);                   // Get the current time (in second)
    tm *now = localtime(&t);                    // Convert time to date
    int currentMonth = now-> tm_mon + 1;        
    int currentYear = now-> tm_year + 1900;

    int expirePasses = 0;

    cout << "Updating......" << endl;

    for (int i = 0; i < appCount; i++){

        if(applist[i].status == "Approved"){             // Check the pass status.

            int validMonth = applist[i].startMonth + (applist[i].duration - 1);
            int validYear = applist[i].startYear;

            if (validMonth > 12){
                validMonth -= 12;
                validYear += 1;
            }
            
            bool expired = (currentYear > validYear) || (currentYear == validYear && currentMonth > validMonth);

            if (expired){
                applist[i].status = "Expired";
                expirePasses++;

                cout << "Alter ID " << applist[i].studentID
                     << " (" << applist[i].studentName << ") to expired" <<endl; 
            }
        }
    }

    if (expirePasses > 0){
        saveApplication();
        cout << "\n Updated Complete." << expirePasses << " passes were altered to Expired. ";
        cout << "Application.txt has been updated. \n";
    
    }else{
        cout << "No passes needed to be Expired this month." << endl;
        cout << "\n1. Back to Admin Menu" << endl;
        cout << "\n2. Back to Main Menu" << endl;
        cout << "\n3. Exit" << endl;

    int opt;
    cin >> opt;

    if (opt == 2){
        step = 0;   // Back to main menu
        return;
    }
    if (opt == 3){
        step = -1;  // Exit 
        return;
    }

    // Back to Admin menu
        step = 3;
        return;       
    }

}