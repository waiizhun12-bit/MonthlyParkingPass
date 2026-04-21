#include <iostream>
#include <string>
#include <iomanip>
#include "system.h"

using namespace std;

void approveRejectApps();

void listPendingApplications(int &step){

    clearScreen();
    loadApplication();

    bool has_pending = false;

        cout << "---------------------------------------------------------------" << endl;
        cout << "-            LIST       PENDING        APPLICATIONS           -" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout <<"| " << setw(10) << left << "App ID" 
             << " | " << setw(14) << left << "Student ID" 
             << " | " << setw(16) << left << "Student Name" 
             << " | " << setw(10) << left << "Status" 
             << " |" << endl;
            cout << "---------------------------------------------------------------" << endl;
        
    for (int i = 0; i < appCount; i++){
        if (appList[i].status == "PENDING")
        {   
            has_pending = true;
            cout << "| " << setw(10) << left << appList[i].appID 
                 << " | " << setw(14) << left << appList[i].studentID 
                 << " | " << setw(16) << left << appList[i].studentName 
                 << " | " << setw(10) << left << appList[i].status 
                 << " |" << endl;
        }   
    }
        cout << "---------------------------------------------------------------" << endl;

    if (!has_pending){
        cout <<"No pending applications found." <<endl;
        cout << "\n1. Back to Admin Menu" << endl;
        cout << "\n2. Back to Main Menu" << endl;

        int go;
        cin >> go;

        if (go == 2){
            step = 0;   // Back to main menu
            clearScreen();
            return;
        }else{
            step = -1;
            clearScreen();
            return;       
        }
    }
    approveRejectApps();
}

void approveRejectApps(){
    string sid;

    //validation for student ID format (7 digits, starts with 21-25)
    while (true) {
        cout <<"Student ID (e.g., 2101234): ";
        cin >> sid;
        
        if (sid.length() == 7) {
            string prefix = sid.substr(0, 2);
            if (prefix >= "21" && prefix <= "25") break;
        }
        cout <<"Invalid! Please enter student ID that same as the List pending applications\n";
    }

    int pendingAmount[appCount];
    int pendingCount = 0;

    for (int i = 0; i < appCount; i++){
        if (appList[i].studentID == sid  && appList[i].status == "PENDING")
        {
            pendingAmount[pendingCount] = i;
            pendingCount++;
        }
    }

    if (pendingCount == 0){
        cout << "No pending applications found for Student ID " << sid << endl;
        return;
    }

    int pilih;
    cout << "1. Approve "<<endl;
    cout << "2. Reject "<<endl;
    cout << "3. Back "<<endl;
    cout << "Enter your choice: " << endl; 
    cin >> pilih;
    
    switch (pilih){
        case 1:
            appList[pendingAmount[0]].status = "APPROVED";
            cout << "Application approved for Student ID " << sid << "." << endl;
            saveApplication();
            clearScreen();
            break;

        case 2:
            appList[pendingAmount[0]].status = "REJECTED";
            cout << "Application rejected for Student ID " << sid << "." << endl;
            saveApplication();
            clearScreen();
            break;
        
        default:
            cout << "Back to main menu.";
            return;    
        }
    
    return;
}