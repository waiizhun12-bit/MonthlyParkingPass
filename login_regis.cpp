#include <iostream>
#include <string>
#include <sstream>
#include "system.h"
using namespace std;

void login (int &step); // Login
void regis (int &step); // Register

void login (int &step) {

	loadStudent();

	int fill = 1;	
	Student newUser;
	bool admin;

	while (step == 1) {
		header("Login");
		
		if (fill >= 1) {
			cout << "Email   : ";
			
			if (fill == 1) {
				cin >> newUser.email;
				
				if (newUser.email.find("@1utar.my") != string::npos) {
					++fill;
				} else if (newUser.email.find("@utar.edu.my") != string::npos) {
					admin = true;
					++fill;
				} else invalid();
			} else cout << newUser.email << endl;
		} 
		
		if (fill >= 2) {
			cout << "Password: ";
			
			if (fill == 2) {
				cin >> newUser.password;
				++fill;
			} else cout << newUser.password << endl;
		}
		
		if (fill == 3) {
			split();
		
			string arr[] = {"Continue", "Redo", "Back", "Exit"};
			
			switch (option(arr, 5)) {
				case 1: step = 4; return;	// student menu
				case 2: step = 3; return;	// admin menu
				case 3: fill = 1; break;	// Redo
				case 4: step = 0; return;	// main menu
				case 5: step = -1; break;	// exit
				default: invalid(); break;
			}
			//system("cls");
		}
	}
}
string toString(int value){
	stringstream ss;
	ss << value;
	return ss.str();
}

void regis (int &step) {
	loadStudent();
	
	int fill = 1;
	Student newStudent;

	while (step == 2) {
		header("Register");
		
		newStudent.userID = "User " + toString(studentCount + 1);	// Automaticlly generate User 1, User 2...Once have new user to register.
		cout << "Your User ID is " << newStudent.userID << endl;	
		
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
				if (newStudent.email.find("@1utar.my") != string::npos) {
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
							
				if (newStudent.nric.size() == 12 ) {
					++fill;
				} else invalid();
			} else cout << newStudent.nric << endl;
		}

		if (fill >= 8) {
			cout << "Vehicle Number	: ";

			if (fill == 8) {
				cin >> newStudent.vehicleNo;
				++fill;
			} else cout << newStudent.vehicleNo << endl;
		}
		
		studentList[studentCount] = newStudent;
		studentCount++;
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
