#include <iostream>
#include <limits>
#include "system.h"
using namespace std;

void viewProfile(int &step, string &currID) {
    clearScreen();
    loadStudent();

    bool found = false;

    cout << "--------------------------------------------------------------------" << endl;
    cout << "-                        VIEW PROFILE                              -" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == currID) {
            cout << "Full Name     : " << studentList[i].name << endl;
            cout << "NRIC          : " << studentList[i].nric << endl;
            cout << "Phone Number  : " << studentList[i].p_num << endl;
            cout << "Student ID    : " << studentList[i].id << endl;
            cout << "Faculty       : " << studentList[i].faculty << endl;
            cout << "Email         : " << studentList[i].email << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student profile not found." << endl;
    }

    cout << "--------------------------------------------------------------------" << endl;
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}