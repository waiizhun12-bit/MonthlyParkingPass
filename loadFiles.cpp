#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "system.h"
using namespace std;

void saveStudent() {
    ofstream outFile("student.txt");
    if (!outFile.is_open()) return;

    for (int i = 0; i < studentCount; i++) {
        outFile << studentList[i].userNo << ","
                << studentList[i].studentID << ","
                << studentList[i].studentName << ","
                << studentList[i].password << ","
                << studentList[i].faculty << ","
                << studentList[i].phone << ","
                << studentList[i].vehicleNo << ","
                << studentList[i].status << ",";
    }
    outFile.close();
}

void loadStudent(){
    ifstream inFile("student.txt");
    if (!inFile.is_open()) return;

    string line;
    studentCount = 0;

    while (getline(inFile, line) && studentCount < MAX_STUDENT){
        stringstream ss(line); // use stringstream to split the data.

        getline(ss, studentList[studentCount].userNo, ',');
        getline(ss, studentList[studentCount].studentID, ',');
        getline(ss, studentList[studentCount].studentName, ',');
        getline(ss, studentList[studentCount].password, ',');
        getline(ss, studentList[studentCount].faculty, ',');
        getline(ss, studentList[studentCount].phone, ',');
        getline(ss, studentList[studentCount].vehicleNo, ',');
        getline(ss, studentList[studentCount].status, ',');

        // Avoid new registration overlap.
        if(!studentList[studentCount].userNo.empty()){
            int currentUserNo = stoi(studentList[studentCount].userNo);
            if (currentUserNo > userNo) userNo = currentUserNo; // update appNO to the highest number found in the file
        }
        studentCount++;
    }
    inFile.close();
}

void saveApplication() {
    ofstream outFile("application.txt");
    if (!outFile.is_open()) return; 

    for (int i = 0; i < appCount; i++) {
        outFile << applist[i].appNo << ","
                << applist[i].studentID << ","
                << applist[i].studentName << ","
                << applist[i].status << ","
                << applist[i].startMonth << ","
                << applist[i].startYear << ","
                << applist[i].duration << endl;
    }
    outFile.close();
}

void loadApplication() {
    ifstream inFile("application.txt");
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
        applist[appCount].startYear = sy.empty() ? 2026 : stoi(sy); // default to 2026 if empty
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
//loadPayment
//savePayment 