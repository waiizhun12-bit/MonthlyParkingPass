#include <iostream>
#include <iomanip>
#include <limits>
#include "system.h"

using namespace std;

void searchStudents(int &step);
void resetStudentPassword(int &step);

void manageStudents(int &step){
    int choice;

    while (step == -1){
        clearScreen();

        cout << "-------------------------------------------------" << endl;
        cout << "-                MANAGE STUDENTS                -" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1. Search Students\n";
        cout << "2. Reset Student Password\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                searchStudents(step);
                break;

            case 2:
                resetStudentPassword(step);
                break;

            case 0:
                clearScreen();
                return;

            default:
                invalid();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
        }
    }
}

void searchStudents(int &step){
    clearScreen();
    loadStudent();

    string keyword;
    bool found = false;

    cin.ignore(1000, '\n');
    cout << "Enter Student ID or Name to search: ";
    getline(cin, keyword);

    cout << "--------------------------------------------------------------------" << endl;
    cout << "-                         SEARCH STUDENTS                          -" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Student ID"
         << " | " << setw(20) << left << "Name"
         << " | " << setw(12) << left << "Phone"
         << " | " << setw(10) << left << "Faculty"
         << " |" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    for (int i = 0; i < studentCount; i++){
        if (studentList[i].id.find(keyword) != string::npos ||
            studentList[i].name.find(keyword) != string::npos){

            found = true;

            cout << "| " << setw(12) << left << studentList[i].id
                 << " | " << setw(20) << left << studentList[i].name
                 << " | " << setw(12) << left << studentList[i].p_num
                 << " | " << setw(10) << left << studentList[i].faculty
                 << " |" << endl;
        }
    }

    cout << "--------------------------------------------------------------------" << endl;

    if (!found){
        cout << "No student found." << endl;
    }

    cout << "\nPress Enter to continue...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void resetStudentPassword(int &step){
    clearScreen();
    loadStudent();

    string sid;
    bool found = false;

    cout << "Enter Student ID: ";
    cin >> sid;

    for (int i = 0; i < studentCount; i++){
        if (studentList[i].id == sid){
            found = true;

            string newPass, confirmPass;

            cout << "Student found: " << studentList[i].name << endl;
            cout << "Enter new password: ";
            cin >> newPass;
            cout << "Confirm new password: ";
            cin >> confirmPass;

            if (newPass == confirmPass){
                studentList[i].password = newPass;
                saveStudent();
                cout << "Password reset successfully.\n";
            } else {
                cout << "Password confirmation does not match.\n";
            }

            break;
        }
    }

    if (!found){
        cout << "Student ID not found." << endl;
    }

    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}