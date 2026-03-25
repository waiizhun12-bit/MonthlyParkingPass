#include <iostream>
#include "system.h"
using namespace std;

void main_menu();

int main ()
{
    main_menu();
}

void main_menu()
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
}