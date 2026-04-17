#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "system.h"
using namespace std;

void saveApplication() {
    ofstream outApplicationFile("application.txt");
    if (!outApplicationFile.is_open()) return; 

    for (int i = 0; i < appCount; i++) {
    outApplicationFile  << appList[i].appID << ","
                        << appList[i].studentID << ","
                        << appList[i].studentName << ","
                        << appList[i].status << ","
                        << appList[i].vehicleNo << ","
                        << appList[i].startMonth << ","
                        << appList[i].startYear << ","
                        << appList[i].duration << endl;
    }
    outApplicationFile.close();
}

void loadApplication() {
    ifstream inApplicationFile("application.txt");
    if (!inApplicationFile.is_open()) return;

    string line;
    appCount = 0;
    appNo = 0;

    while (getline(inApplicationFile, line) && appCount < MAX_APPLICATIONS){
        stringstream ss(line); // use stringstream to split the data.

        string sm, sy, dur;

        getline(ss, appList[appCount].appID, ',');
        getline(ss, appList[appCount].studentID, ',');
        getline(ss, appList[appCount].studentName, ',');
        getline(ss, appList[appCount].status, ',');
        getline(ss, appList[appCount].vehicleNo, ',');
        getline(ss, sm, ',');
        getline(ss, sy, ',');
        getline(ss, dur);

        appList[appCount].startMonth = sm.empty() ? 1 : toInteger(sm); // default to 1 if empty
        appList[appCount].startYear = sy.empty() ? 2026 : toInteger(sy); // default to 2026 if empty
        appList[appCount].duration = dur.empty() ? 1 : toInteger(dur); // default to 1 if empty

        // Avoid new registration overlap.
        if(!appList[appCount].appID.empty()){
            int currentAppNo = toInteger(appList[appCount].appID);
            if (currentAppNo > appNo) appNo = currentAppNo; // update appNO to the highest number found in the file
        }
        appCount++;
    }
    inApplicationFile.close();
}

void saveStudent() {
    ofstream outStudentFile("student.txt");
    if (!outStudentFile.is_open()){
        cout << "Cannot open student.txt for writing.\n";
        return;
    } 

    for (int i = 0; i < studentCount; i++) {
    outStudentFile << studentList[i].name << ","
                    << studentList[i].nric << ","
                    << studentList[i].p_num << ","
                    << studentList[i].id << ","
                    << studentList[i].faculty << ","
                    << studentList[i].email << ","
                    << studentList[i].password << endl;   
    }
    outStudentFile.close();
    cout << "Student data saved.\n";
}

void loadStudent(){
    ifstream inStudentFile("student.txt");
    if (!inStudentFile.is_open()) return;

    string line;
    studentCount = 0;

    while (getline(inStudentFile, line) && studentCount < MAX_STUDENT){
        stringstream ss(line); // use stringstream to split the data.

        getline(ss, studentList[studentCount].name, ',');
        getline(ss, studentList[studentCount].nric, ',');
        getline(ss, studentList[studentCount].p_num, ',');
        getline(ss, studentList[studentCount].id, ',');
        getline(ss, studentList[studentCount].faculty, ',');
        getline(ss, studentList[studentCount].email, ',');
        getline(ss, studentList[studentCount].password, ',');

        studentCount++;
    }
    inStudentFile.close();
}

void loadPayment(){
    ifstream inPaymentFile("payment.txt");
    if (!inPaymentFile.is_open()) return;

    string line;
    payCount = 0;

    while (getline(inPaymentFile, line) && payCount < MAX_PAYMENTS){
        stringstream ss(line); // use stringstream to split the data.
        string am;

        getline(ss, payList[payCount].paymentID, ',');
        getline(ss, payList[payCount].studentID, ',');
        getline(ss, payList[payCount].paymentStatus, ',');
        getline(ss, am, ',');
        getline(ss, payList[payCount].paymentDate);

        payList[payCount].amount = am.empty() ? 0.0 : toDouble(am);

        // Avoid new registration overlap.
        if(!payList[payCount].paymentID.empty()){
            int currentpaymentID = toInteger(payList[payCount].paymentID);
            if (currentpaymentID > payNo) payNo = currentpaymentID; 
        }
        payCount++;
    }
    inPaymentFile.close();
}


void savePayment(){
        ofstream outPaymentFile("payment.txt");
        if (!outPaymentFile.is_open()) return;

        for (int i = 0; i < payCount; i++) {
         outPaymentFile << payList[i].paymentID << ","
                        << payList[i].studentID << ","
                        << payList[i].paymentStatus << ","
                        << payList[i].amount << ","
                        << payList[i].paymentDate << endl;
    }
    outPaymentFile.close();
} 