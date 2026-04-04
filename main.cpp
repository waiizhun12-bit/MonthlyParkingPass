#include <iostream>
#include <string>
#include "system.h"
using namespace std;

void menu (int &step);  // Main menu

int main () {
    int step = 0;

    while (step >= 0) {
        if (step == 0) menu(step);
        if (step == 1) login(step);
        if (step == 2) regis(step);
        if (step == 3) admin_menu(step);
    }
}

void menu (int &step) {
	header("Main Menu");
	
	string arr[] = {"Login","Register","Exit"};

    switch (option(arr, 3)) {
        case 1: step = 1; break;
        case 2: step = 2; break;
        case 3: step = -1; break;
        default: invalid(); break;
    }
}

/*void main_menu()
{
    int choice;
    cout <<"---------------------------------"<<endl;
    cout <<"|  MONTHLY PARKING PASS SYSTEM  |"<<endl;
    cout <<"---------------------------------"<<endl;

    cout <<" 1. Admin Module                -"<<endl;
    cout <<" 2. Student Module              -"<<endl;
    cout <<" 0. Exit / Shutdown             -"<<endl;
    cout <<"---------------------------------" <<endl;

    cout <<"Enter your choice: \n";
    cin >> choice;

    switch (choice) {
        case 1:
            admin_menu(); 
            break;
        case 2:
            studentAuth_menu(); 
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}*/