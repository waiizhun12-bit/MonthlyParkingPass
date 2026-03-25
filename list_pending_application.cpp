#include <iostream>
#include "system.h"

using namespace std;

void list_pending_applications(){

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

    cout <<"------------------------------------------------------"<<endl;
    cout <<"-               List PENDING APPLICATIONS            -"<<endl;
    cout <<"------------------------------------------------------"<<endl;
    cout <<"|   Student ID   |     Student Name     |   Status   |"<<endl;
    cout <<"------------------------------------------------------"<<endl;

    bool haspending = false;

    for (int i = 0; i < 4; i++){
        if (applist[i].status == "Pending")
        {
            cout <<"|   " <<applist[i].studentID 
                 <<"   |   " <<applist[i].studentName;

        if (applist[i].studentName.length() < 20) cout <<"\t";

            cout <<"   |   " <<applist[i].status <<"   |"<<endl;
        }
        haspending = true;
    }

    if (!haspending){
        cout <<"No pending applications found." <<endl;
    }
}