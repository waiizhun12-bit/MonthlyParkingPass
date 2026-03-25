#include <iostream>
#include <string>
#include <iomanip>
#include "system.h"

using namespace std;

int listPendingApps();
int approveRejectApps();


// global variable for testing, need to replace with actual data from text file
struct Application {
        string studentID;
        string studentName;
        string status; // Pending, Approved, Rejected
};

//temporary data for testing list pending application, need to replace with actual data from text file
Application applist[4] = {
        {"S12345", "Alice Johnson", "Pending"},
        {"S67890", "Bob Smith", "Pending"},
        {"S54321", "Charlie Brown", "Approved"},
        {"S98765", "Diana Prince", "Rejected"}
};

void list_pending_applications(){

    listPendingApps();
   
}

int listPendingApps(){

    int appCount = 4;
    
    cout <<"---------------------------------------------------------------"<<endl;
    cout <<"-                   List PENDING APPLICATIONS                 -"<<endl;
    cout <<"---------------------------------------------------------------"<<endl;
    cout <<"|   App No.   |   Student ID   |   Student Name   |   Status  |"<<endl;
    cout <<"---------------------------------------------------------------"<<endl;

    bool has_pending = false;
    int appNo = 1;

    for (int i = 0; i < appCount; i++){
        if (applist[i].status == "Pending")
        {   
            has_pending = true;

            cout <<"| " << setw(10) << left << appNo 
                 << "  | " << setw(14) << left << applist[i].studentID 
                 << " | " << setw(16) << left << applist[i].studentName 
                 << " | " << setw(9) << left << applist[i].status 
                 << " |" << endl;
            appNo++;
        }
    }

    if (!has_pending){
        cout <<"No pending applications found." <<endl;
    }

    return 0;       
}

int approveRejectApps(){
    

    return 0;
}