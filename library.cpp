#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>
#include "system.h"
using namespace std;

Application appList[MAX_APPLICATIONS];
int appCount = 0;
int appNo = 1;

Student studentList[MAX_STUDENT];
int studentCount = 0;
int userNo = 1;

Payment payList[MAX_PAYMENTS];
int payCount = 0;
int payNo =1;

void clearScreen(){

	system("cls");
}
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

int toInteger(const string& s){
	stringstream ss(s);
	int value = 0;
	ss >> value;
	return value;	
}

string toString(int value){
	stringstream ss;
	ss << value;
	return ss.str();
}

double toDouble(const string& str) {
    stringstream ss(str);
    double result;
    ss >> result;
    return result;
}
