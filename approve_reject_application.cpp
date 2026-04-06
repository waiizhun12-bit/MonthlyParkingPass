#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "system.h"

using namespace std;

int listPendingApps(int &step);
int approveRejectApps();

void list_pending_applications(int &step){

    loadApplication();
    listPendingApps(step);

    bool has_pending = false;

    for (int i = 0; i < appCount; i++){
        if (applist[i].status == "Pending")
        {   
            has_pending = true;

            cout <<"| " << setw(10) << left << applist[i].appNo 
                 << " | " << setw(14) << left << applist[i].studentID 
                 << " | " << setw(16) << left << applist[i].studentName 
                 << " | " << setw(10) << left << applist[i].status 
                 << " |" << endl;
        }
    }

    if (!has_pending){
        cout <<"No pending applications found." <<endl;
        cout << "\n1. Back to Admin Menu" << endl;
        cout << "\n2. Back to Main Menu" << endl;
        cout << "\n3. Exit" << endl;

    int go;
    cin >> go;

    if (go == 2){
        step = 0;   // Back to main menu
        return;
    }
    if (go == 3){
        step = -1;  // Exit 
        return;
    }

    // Back to Admin menu
        step = 3;
        return;       
    }

    approveRejectApps();
   
}

int listPendingApps(int &step){
    
    cout << "---------------------------------------------------------------" << endl;
    cout << "-            LIST       PENDING        APPLICATIONS           -" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout <<"| " << setw(10) << left << "App No" 
         << " | " << setw(14) << left << "Student ID" 
         << " | " << setw(16) << left << "Student Name" 
         << " | " << setw(10) << left << "Status" 
         << " |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    return 0;
}
int approveRejectApps(){
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
        if (applist[i].studentID == sid  && applist[i].status == "Pending")
        {
            pendingAmount[pendingCount] = i;
            pendingCount++;
        }
    }

    if (pendingCount == 0){
        cout << "No pending applications found for Student ID " << sid << endl;
        return 0;
    }

    int pilih;
    cout << "1. Approve "<<endl;
    cout << "2. Reject "<<endl;
    cout << "3. Back "<<endl;
    cout << "Enter your choice: " << endl; 
    cin >> pilih;
    
    switch (pilih){
        case 1:
            applist[pendingAmount[0]].status = "Approved";
            cout << "Application approved for Student ID " << sid << "." << endl;
            saveApplication();
            break;

        case 2:
            applist[pendingAmount[0]].status = "Rejected";
            cout << "Application rejected for Student ID " << sid << "." << endl;
            saveApplication();
            break;
        
        default:
            cout << "Back to main menu.";
            return 0;    
        }
    
    return 0;
}