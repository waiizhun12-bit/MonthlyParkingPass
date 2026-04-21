#include <iostream>
#include <limits>
#include "system.h"
using namespace std;

void resetPassword(int &step, string &currID) {
    clearScreen();
    loadStudent();

    int index = -1;             // If studnet found in List index will become 0, 1, 2. So, if index stay -1 that means this student no profile.
    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == currID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Student account not found." << endl;
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    string oldPw, newPw, confirmPw;

    cout << "--------------------------------------------------------------------" << endl;
    cout << "-                          RESET PASSWORD                          -" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    cout << "Enter current password : ";
    cin >> oldPw;

    if (oldPw != studentList[index].password) {
        cout << "Wrong current password." << endl;
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    cout << "Enter new password     : ";
    cin >> newPw;

    cout << "Confirm new password   : ";
    cin >> confirmPw;

    if (newPw != confirmPw) {
        cout << "New password and confirmation do not match." << endl;
    } 
    else if (newPw == oldPw) {
        cout << "New password cannot be same as current password." << endl;
    }
    else if (newPw.empty()) {
        cout << "Password cannot be empty." << endl;
    }
    else {
        studentList[index].password = newPw;
        saveStudent();
        cout << "Password reset successfully." << endl;
    }

    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}