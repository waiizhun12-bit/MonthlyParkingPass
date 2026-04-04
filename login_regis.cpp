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
		
			string arr[] = {"Continue", "Redo", "Back", "Exit"};
			
			switch (option(arr, 4)) {
				case 1: step = 3; return;
				case 2: fill = 1; break;
				case 3: step = 0; return;
				case 4: step = -1; break;
				default: invalid(); break;
			}
			//system("cls");
		}
	}
}

void regis (int &step) {
	int fill = 1;
	string f_name, l_name, email, password, p_num, nric;
		
	while (step == 2) {
		header("Register");
		
		if (fill >= 1) {
			cout << "First name  : ";
			
			if (fill == 1) {
				cin >> f_name;
				++fill;
			} else cout << f_name << endl;
		}
		
		if (fill >= 2) {
			cout << "Last name   : ";
			
			if (fill == 2) {
				cin >> l_name;
				++fill;
			} else cout << l_name << endl;
		}
		
		if (fill >= 3) {
			cout << "Email       : ";
			
			if (fill == 3) {
				cin >> email;
				if (email.find("@1utar.my") != string::npos) {
					++fill;
				} else invalid();
			} else cout << email << endl;			
		}
		
		if (fill >= 4) {
			cout << "Password    : ";
			
			if (fill == 4) {
				cin >> password;
				++fill;
			} else cout << password << endl;
		}
		
		if (fill >= 5) {
			cout << "Phone number: ";
			
			if (fill == 5) {
				cin >> p_num;
				
				if (p_num.size() == 10 || p_num.size() == 11) {
					++fill;
				} else invalid();
			} else cout << p_num << endl;
		}
		
		if (fill >= 6) {
			cout << "NRIC number : ";
			
			if (fill == 6) {
				cin >> nric;
							
				if (nric.size() == 12) {
					++fill;
				} else invalid();
			} else cout << nric << endl;
		}
		
		if (fill == 7) {
			split();
		
			string arr[] = {"Continue", "Redo", "Back", "Exit"};
			
			switch (option(arr, 4)) {
				case 1: step = 3; break;
				case 2: fill = 1; break;
				case 3: step -= 1; break;
				case 4: step = -1; break;
				default: invalid(); break;
			}
			
			//system("cls");
		}
	}
}