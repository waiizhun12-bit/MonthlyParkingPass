#include <iostream>
#include <string>
#include "system.h"
using namespace std;

void login (int &step); // Login
void regis (int &step); // Register

void login (int &step) {
	int fill = 1;	
	string email, password;

	while (step == 1) {
		header("Login");
		
		if (fill >= 1) {
			cout << "Email   : ";
			
			if (fill == 1) {
				cin >> email;
				
				if (email.find("@1utar.my") != string::npos) {
					++fill;
				} else invalid();
			} else cout << email << endl;
		} 
		
		if (fill >= 2) {
			cout << "Password: ";
			
			if (fill == 2) {
				cin >> password;
				++fill;
			} else cout << password << endl;
		}
		
		if (fill == 3) {
			split();
		
			string arr[] = {"Continue to Student Menu","Continue to Admin Menu", "Redo", "Back", "Exit"};
			
			switch (option(arr, 5)) {
				case 1: step = 4; return;	
				case 2: step = 3; return;
				case 3: fill = 1; break;
				case 4: step = 0; return;
				case 5: step = -1; break;
				default: invalid(); break;
			}
			//system("cls");
		}
	}
}

void regis (int &step) {
	loadStudent();
	
	int fill = 1;
	Student newStudent;
	
	newStudent.userID = "User" + to_string(studentCount + 1);	// Automaticlly generate User 1, User 2...Once have new user to register.
	cout << "Your User ID is " << newStudent.userID << endl;

	while (step == 2) {
		header("Register");
		
		if (fill >= 1) {
			cout << "Student ID  : ";
			
			if (fill == 1) {
				cin >> newStudent.studentID;
				++fill;
			} else cout << newStudent.studentID << endl;
		}
		
		if (fill >= 2) {
			cout << "Name   : ";
			
			if (fill == 2) {
				cin >> newStudent.studentName;
				++fill;
			} else cout << newStudent.studentName << endl;
		}
		
		if (fill >= 3) {
			cout << "Email       : ";
			
			if (fill == 3) {
				cin >> newStudent.email;
				if (email.find("@1utar.my") != string::npos) {
					++fill;
				} else invalid();
			} else cout << newStudent.email << endl;			
		}
		
		if (fill >= 4) {
			cout << "Password    : ";
			
			if (fill == 4) {
				cin >> newStudent.password;
				++fill;
			} else cout << newStudent.password << endl;
		}
		
		if (fill >= 5) {
			cout << "Phone number	: ";
			
			if (fill == 5) {
				cin >> newStudent.phone;
				
				if (newStudent.phone.size() >= 10 || newStudent.phone.size() <= 11) {
					++fill;
				} else invalid();
			} else cout << newStudent.phone << endl;
		}
		
		if (fill >= 6) {
			cout << "Faculty	: ";

			if (fill == 6) {
				cin >> newStudent.faculty;
				++fill;
			}else cout << newStudent.faculty << endl;
		}

		if (fill >= 7) {
			cout << "NRIC number	: ";
			
			if (fill == 7) {
				cin >> newStudent.nric;
							
				if (newStudent.nric.size() >= 12) {
					++fill;
				} else invalid();
			} else cout << newStudent.nric << endl;
		}

		if (fill >= 8) {
			cout << "Vehicle Number		: ";

			if (fill == 8) {
				cin >> newStudent.vehicleNo;
				++fill;
			} else cout << newStudent.vehicleNo << endl;
		}
		saveStudent();
		
		if (fill == 9) {
			split();
		
			string arr[] = {"Continue to Student Menu", "Redo", "Back", "Exit"};
			
			switch (option(arr, 4)) {
				case 1: step = 4; break;
				case 2: fill = 1; break;
				case 3: step -= 1; break;
				case 4: step = -1; break;
				default: invalid(); break;
			}
			
			//system("cls");
		}
	}
}