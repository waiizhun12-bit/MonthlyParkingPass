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
        outApplicationFile << appList[i].appID << ","
                           << appList[i].studentID << ","
                           << appList[i].studentName << ","
                           << appList[i].status << ","
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

    while (getline(inApplicationFile, line) && appCount < MAX_APPLICATIONS){
        stringstream cc(line); // use stringstream to split the data.

        string sm, sy, dur;

        getline(cc, appList[appCount].appID, ',');
        getline(cc, appList[appCount].studentID, ',');
        getline(cc, appList[appCount].studentName, ',');
        getline(cc, appList[appCount].status, ',');
        getline(cc, sm, ',');
        getline(cc, sy, ',');
        getline(cc, dur, ',');

        appList[appCount].startMonth = sm.empty() ? 1 : stoi(sm); // default to 1 if empty
        appList[appCount].startYear = sy.empty() ? 2026 : stoi(sy); // default to 2026 if empty
        appList[appCount].duration = dur.empty() ? 1 : stoi(dur); // default to 1 if empty

        // Avoid new registration overlap.
        if(!appList[appCount].appID.empty()){
            int currentAppNo = stoi(appList[appCount].appID);
            if (currentAppNo > appNo) appNo = currentAppNo; // update appNO to the highest number found in the file
        }

        appCount++;
    }
    inApplicationFile.close();
}

void saveStudent() {
    ofstream outStudentFile("student.txt");
    if (!outStudentFile.is_open()) return;

    for (int i = 0; i < studentCount; i++) {
        outStudentFile << studentList[i].userID << ","
                       << studentList[i].studentID << ","
                       << studentList[i].studentName << ","
                       << studentList[i].email << ","
                       << studentList[i].password << ","
                       << studentList[i].phone << ","
                       << studentList[i].faculty << ","
                       << studentList[i].nric << ","
                       << studentList[i].vehicleNo << ",";
    }
    outStudentFile.close();
}

void loadStudent(){
    ifstream inStudentFile("student.txt");
    if (!inStudentFile.is_open()) return;

    string line;
    studentCount = 0;

    while (getline(inStudentFile, line) && studentCount < MAX_STUDENT){
        stringstream ss(line); // use stringstream to split the data.

        getline(ss, studentList[studentCount].userID, ',');
        getline(ss, studentList[studentCount].studentID, ',');
        getline(ss, studentList[studentCount].studentName, ',');
        getline(ss, studentList[studentCount].email, ',');
        getline(ss, studentList[studentCount].password, ',');
        getline(ss, studentList[studentCount].phone, ',');
        getline(ss, studentList[studentCount].faculty, ',');
        getline(ss, studentList[studentCount].nric, ',');
        getline(ss, studentList[studentCount].vehicleNo, ',');

        // Avoid new registration overlap.
        if(!studentList[studentCount].userID.empty()){
            int currentUserNo = stoi(studentList[studentCount].userID);
            if (currentUserNo > userNo) userNo = currentUserNo; // update appNO to the highest number found in the file
        }
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
        getline(ss, payList[payCount].appID, ',');
        getline(ss, payList[payCount].studentID, ',');
        getline(ss, payList[payCount].paymentStatus, ',');
        getline(ss, payList[payCount].paymentDate, ',');
        getline(ss, am, ',');

        // Avoid new registration overlap.
        if(!payList[payCount].paymentID.empty()){
            int currentpaymentID = stoi(payList[payCount].paymentID);
            if (currentpaymentID > payNo) payNo = currentpaymentID; // update appNO to the highest number found in the file
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
                           << payList[i].appID << ","
                           << payList[i].studentID << ","
                           << payList[i].paymentStatus << ","
                           << payList[i].paymentDate << ","
                           << payList[i].amount << ",";
    }
    outPaymentFile.close();
} 