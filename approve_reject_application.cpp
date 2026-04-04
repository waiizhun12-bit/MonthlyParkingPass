#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
#include "system.h"

using namespace std;

void saveFile();
void loadFile();
int listPendingApps();
int approveRejectApps();

void list_pending_applications(){

    loadFile();
    listPendingApps();
    approveRejectApps();
   
}

void saveFile() {
    ofstream outFile("students.txt");
    if (!outFile.is_open()) return; 

    for (int i = 0; i < appCount; i++) {
        outFile << applist[i].appNo << ","
                << applist[i].studentID << ","
                << applist[i].studentName << ","
                << applist[i].status << ", "
                << applist[i].startMonth << ", "
                << applist[i].startYear << ", "
                << applist[i].duration << endl;
    }
    outFile.close();
}

void loadFile() {
    ifstream inFile("students.txt");
    if (!inFile.is_open()) return;

    string line;
    appCount = 0;

    while (getline(inFile, line) && appCount < MAX_STUDENT){
        stringstream cc(line); // use stringstream to split the data.

        string sm, sy, dur;

        getline(cc, applist[appCount].appNo, ',');
        getline(cc, applist[appCount].studentID, ',');
        getline(cc, applist[appCount].studentName, ',');
        getline(cc, applist[appCount].status, ',');
        getline(cc, sm, ',');
        getline(cc, sy, ',');
        getline(cc, dur, ',');

        applist[appCount].startMonth = sm.empty() ? 1 : stoi(sm); // default to 1 if empty
        applist[appCount].startYear = sy.empty() ? 2026 : stoi(sy); // default to 2024 if empty
        applist[appCount].duration = dur.empty() ? 1 : stoi(dur); // default to 1 if empty

        // Avoid new registration overlap.
        if(!applist[appCount].appNo.empty()){
            int currentAppNo = stoi(applist[appCount].appNo);
            if (currentAppNo > appNO) appNO = currentAppNo; // update appNO to the highest number found in the file
        }

        appCount++;
    }
    inFile.close();
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
            saveFile();
            break;

        case 2:
            applist[pendingAmount[0]].status = "Rejected";
            cout << "Application rejected for Student ID " << sid << "." << endl;
            saveFile();
            break;
        
        default:
            cout << "Back to main menu.";
            return 0;    
        }
    
    return 0;
}