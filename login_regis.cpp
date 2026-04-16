#include <iostream>
#include <string>
#include <cstdlib>
#include "system.h"
using namespace std;

void login(int &step, string &currID); // Login
void regis(int &step); // Register

void login (int &step, string &currID) {
	clearScreen();
	loadStudent();
	
	string email, password;
	bool admin = false;
	bool found = false;
	int fill = 1;

	while (step == 1) {
		header("Login");
		
		if (fill >= 1) {
			cout << "Email    : ";
			
			if (fill == 1) {
				cin >> email;
				
				if (email.find("@1utar.my") != string::npos) {
					fill++;
				} else if (email.find("@utar.edu.my") != string::npos) {
					admin = true;
					fill++;
				} else invalid();
			} else 
				cout << email << endl;
		} 
		
		if (fill >= 2) {
			cout << "Password : ";
			
			if (fill == 2) {
				cin >> password;
				fill++;
			} else 
				cout << password << endl;
		}

		for (int i = 0; i < studentCount; i++) {
    		if (email == studentList[i].email && password == studentList[i].password) {
        	currID = studentList[i].id;
			found = true;
       		break;
    		}
	    }

		if (fill == 3) {
			split();
		
			string arr[] = {"Continue", "Redo", "Back", "Exit"};
			
			switch (option(arr, 4)) {
				case 1:
					if (admin) {
						step = -1;   // admin menu
					} else {
						step = 3;   // student menu
						monthEndRenewalAlert(currID);
					}
					break;
				case 2: fill = 1; break;				// Redo
				case 3: step -= 1; break;				// Back
				case 4: step = 99; break;				// Exit
				default: invalid(); break;
			}
			system("cls");
		}
	}
}

void regis(int &step, string &currID) {
	
	loadApplication();

	string name, nric, p_num, id, faculty, email, password;
	int fill = 1;

	while (step == 2) {
		header("Register");
		
		if (fill >= 1) {
			cout << "Personal Information\n";
			split();
			
			cout << "Full Name (as per IC)      : ";
			
			if (fill == 1) {
				cin.ignore();
				getline(cin, name);
				
				if (name == "") 
					invalid();
				else 
					fill++;
			} else 
				cout << name << endl;
		}
		
		if (fill >= 2) {
			cout << "NRIC Number (without '-')  : ";
			
			if (fill == 2) {
				cin >> nric;
							
				if (nric.size() == 12 ) {
					fill++;
				} else invalid();
			} else 
				cout << nric << endl;
		}
		
		if (fill >= 3) {
			cout << "Phone Number (without '-') : ";
			
			if (fill == 3) {
				cin >> p_num;
				
				if (p_num.size() >= 10 || p_num.size() <= 11) {
					fill++;
				} else invalid();
			} else 
				cout << p_num << endl;
		}
		
		if (fill >= 4) {
			split();
			cout << "Academic Information" << endl;
			split();
			
			cout << "Student ID (in full)       : ";
			
			if (fill == 4) {
				cin >> id;
				fill++;
			} else 
				cout << id << endl;
		}
		
		if (fill >= 5) {
			cout << "Faculty (in abbreviation)  : ";
			
			if (fill == 5) {
				cin.ignore();
				getline(cin, faculty);
				
				if (faculty == "")
					invalid();
				else
					fill++;
			} else
				cout << faculty << endl;
		}

		if (fill >= 6) {
			cout << "\n---------------Security Information---------------\n";
			
			cout << "Email                      : ";
			
			if (fill == 6) {
				cin >> email;
				if (email.find("@1utar.my") != string::npos) {
					fill++;
				} else invalid();
			} else 
				cout << email << endl;	
		}
		
		if (fill >= 7) {
			cout << "Password                   : ";
			
			if (fill == 7) {
				cin >> password;
				fill++;
			} else 
				cout << password << endl;
		}

		clearScreen();
		
		if (fill == 8) {
			split();
		
			string arr[] = {"Continue", "Redo", "Back", "Exit"};
			
			switch (option(arr, 4)) {
				case 1: {
					STUDENT s;
					s.name = name;
					s.nric = nric;
					s.p_num = p_num;
					s.id = id;
					s.faculty = faculty;
					s.email = email;
					s.password = password;

					studentList[studentCount] = s;
					studentCount++;
					saveStudent();

					currID = id;
					step = 3; 				// Student Menu
					return;	
				}
				case 2: fill = 1; break;	// Register
				case 3: step -= 1; break;	// Main Menu
				case 4: step = 99; break;	// Exit
				default: invalid(); break;
			}
			
			system("cls");
		}
	}
}