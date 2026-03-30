#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "system.h"

using namespace std;

// global variable for testing, need to replace with actual data from text file
struct Application {
        string appNo;
        string studentID;
        string studentName;
        string status; // Pending, Approved, Rejected
};


int appCount = 4; //State the number of applications in the system, need to replace a maximum number of students
int appNo = 0; //State the application number, need to replace with actual data from text file

//temporary data for testing list pending application, need to replace with actual data from text file
Application applist[4] = {
        {to_string(appNo), "2404544", "Alice Johnson", "Pending"},
        {to_string(++appNo), "2404545", "Bob Smith", "Pending"},
        {to_string(++appNo), "2404546", "Charlie Brown", "Approved"},
        {to_string(++appNo), "2404547", "Diana Prince", "Rejected"}
};

int listPendingApps();
int approveRejectApps();

void list_pending_applications(){

    listPendingApps();
    approveRejectApps();
   
}

int listPendingApps(){
    
    cout <<"---------------------------------------------------------------"<<endl;
    cout <<"-                   LIST PENDING APPLICATIONS                 -"<<endl;
    cout <<"---------------------------------------------------------------"<<endl;
    cout <<"| " << setw(10) << left << "App No" 
         << " | " << setw(14) << left << "Student ID" 
         << " | " << setw(16) << left << "Student Name" 
         << " | " << setw(10) << left << "Status" 
         << " |" << endl;
    cout <<"---------------------------------------------------------------"<<endl;

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
    }

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
            break;

        case 2:
            applist[pendingAmount[0]].status = "Rejected";
            cout << "Application rejected for Student ID " << sid << "." << endl;
            break;
        
        default:
            cout << "Back to main menu.";
            admin_menu();    
        }
    
    return 0;
}