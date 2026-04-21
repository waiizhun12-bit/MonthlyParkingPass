#include <iostream>
#include <limits>
#include <cctype>
#include "system.h"
using namespace std;

bool isDigit(string text);

void updateProfile(int &step, string &currID) {
    clearScreen();
    loadStudent();

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == currID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Student profile not found." << endl;
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    int choice;
    do {
        clearScreen();
        cout << "--------------------------------------------------------------------" << endl;
        cout << "-                          UPDATE PROFILE                          -" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "1. Update Phone Number" << endl;
        cout << "2. Update Faculty" << endl;
        cout << "3. Update Email" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            invalid();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                string newPhone;
                cout << "\nEnter new phone number: ";
                getline(cin, newPhone);

                if (newPhone.size() >= 10 && newPhone.size() <= 11) {
                    studentList[index].p_num = newPhone;
                    saveStudent();
                    cout << "Phone number updated successfully." << endl;
                } else {
                    cout << "Invalid phone number." << endl;
                }
                break;
            }

            case 2: {
                string newFaculty;
                cout << "\nEnter new faculty : ";
                getline(cin, newFaculty);

                if (newFaculty.empty()) {
                    invalid();
                } else {
                    cout << "New Faculty updated successfully." << endl;
                }
                break;
            }

            case 3: {
                string newEmail;
                cout << "\nEnter new email: ";
                getline(cin, newEmail);

                if (newEmail.find("@1utar.my") != string::npos) {
                    studentList[index].email = newEmail;
                    saveStudent();
                    cout << "Email updated successfully." << endl;
                } else {
                    cout << "Invalid email. Must end with @1utar.my" << endl;
                }
                break;
            }

            case 0:
                return;

            default:
                invalid();
        }

        cout << "Press Enter to continue...";
        cin.get();

    } while (choice != 0);
}