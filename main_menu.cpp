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
    cout <<"---------------------------------\n";
    cout <<"|  MONTHLY PARKING PASS SYSTEM  | \n";
    cout <<"---------------------------------"<<endl;

    cout <<" 1. Admin Module                - \n";
    cout <<" 2. Student Module              - \n";
    cout <<" 0. Exit / Shutdown             - \n";
    cout <<"---------------------------------\n";

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