#include <iostream>
#include <iomanip>
#include <string>
#include "system.h"
using namespace std;

Application applist[MAX_STUDENT];
int appCount = 0;
int appNO = 1;

Student studentList[MAX_STUDENT];
int studentCount = 0;
int userNo = 1;

void split (void) {
	cout << "--------------------------------------------------" << endl; 
}

void header (string sub) {
	split();
	
	string title = "MONTHLY PARKING PASS SYSTEM";
	string tab = "[" + sub + "]";

	cout << setw(30) << left << title;
	cout << setw(20) << right << tab << endl;
		 
	split();
}

int option (string array[], int size) {				
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "." << array[i] << endl;
	}
	
	split();
	cout << "Enter option: ";
	
	int opt;
	cin >> opt;
	
	if (opt > 0 && opt <= size) {
		//system("cls");
		return opt;
	} else return 0;
}

void invalid (void) {
	cout << "\nInvalid input!\n"
		 << "Press enter to try again: ";
	
	cin.ignore();
	cin.get();
	
	//system("cls");
}