#include <iostream>
#include <string>
#include "system.h"
using namespace std;


void manageStudents();
void searchStudents();
void toggleStudentStatus();
void resetStudentPassword();

void manageStudents() {
    int choice;

    do {
        cout << "\n===== MANAGE STUDENTS =====\n";
        cout << "1. Search Student\n";
        cout << "2. Activate/Deactivate Student\n";
        cout << "3. Reset Student Password\n";
        cout << "0. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                searchStudents();
                break;
            case 2:
                toggleStudentStatus();
                break;
            case 3:
                resetStudentPassword();
                break;
            case 0:
                cout << "Returning...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

void searchStudents() {
    string studentId;
    cout << "\nEnter Student ID: ";
    cin >> studentId;

    bool found = false;

    for (int i = 0; i < studentCount; i++) {
        if (studentList[studentCount].studentID == studentId) {
            cout << "\nStudent Found:\n";
            cout << "ID: " << studentList[studentCount].studentID << endl;
            cout << "Name: " << studentList[studentCount].studentName << endl;
            cout << "Status: " << (studentList[studentCount].isActive ? "Active" : "Inactive") << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n"; 
    }
}

void toggleStudentStatus() {
    string studentId;
    cout << "\nEnter Student ID: ";
    cin >> studentId;

    bool found = false;

    for (int i = 0; i < studentCount; i++) {
        if (studentList[studentCount].studentID == studentId) {
            studentList[studentCount].isActive = !studentList[studentCount].isActive;

            cout << "Status updated to: "
                 << (studentList[studentCount].isActive ? "Active" : "Inactive") << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

void resetStudentPassword() {
    string studentId;
    cout << "\nEnter Student ID: ";
    cin >> studentId;

    bool found = false;

    for (int i = 0; i < studentCount; i++) {
        if (studentList[studentCount].studentID == studentId) {
            string newPass;
            cout << "Enter new password: ";
            cin >> newPass;

            studentList[studentCount] = newPass;

            cout << "Password reset successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}