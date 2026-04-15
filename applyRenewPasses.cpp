/*
1. A prompt let user choose apply or renew their pass.(done)
2. After choosing, shift to the particular page.(done)
3. In apply pass, user need to enter their name, vehicle no, start month, start year, duration. (done)
4. After selecting apply, then go to makePayment.cpp. 
5. In that page, show the details entered just now, as well as total price.
6. Allow user to select payment method, by key in the command, show the payment prompt, but just changing the payment method in the prompt. 
7. Then go back to Apply or Renew page, then go through the renew part.
8. A prompt show student name, and allow user to key in vehicle no, start month, start year, and duration. 
9. Then go to payment page, show prompt, included all the details as well as total price, and select payment method.
10. After paid, go back to aplly or renew page, then user can select "exit", and back to student menu.
*/

#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "system.h"
using namespace std;

void applyPass(int &step, string &currID);
void renewPass(int &step, string &currID);
void makePayment();
double calPaymentAmount();

void applyRenewPasses(int &step, string &currID){
    clearScreen();
    loadApplication();

    int choice;
    cout << "1. Apply Month Parking Pass\n";
    cout << "2. Renew Pass\n";
    cout << "3. Exit" << endl; 
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
        applyPass(step, currID);
        break;

    case 2:
        //renewPass(step, currID);
        break;
    
    case 0:
        return;

    default:
        invalid();
    }
}

void applyPass(int &step, string &currID){
    clearScreen();
    loadStudent();
    loadApplication();

    string name, vehicleNo;
    int startMonth, startYear, duration;

    cout << "---------------------------------------------------------------------" << endl;
    cout << "                          APPLY NEW PASS                            -" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "- Student ID: " << currID << endl;

    cin.ignore(1000, '\n');

    cout << "- Enter student name: ";
    getline(cin, name);

    cout << "- Enter vehicle no   : ";
    getline(cin, vehicleNo);

    cout << "- Enter start month (1-12): ";
    cin >> startMonth;

    cout << "- Enter start year        : ";
    cin >> startYear;

    cout << "- Enter duration (1-3)    : ";
    cin >> duration;

    if (startMonth < 1 || startMonth > 12){
        cout << "Invalid month.\n";
        cin.ignore(1000, '\n');
        cin.get();
        return;
    }

    if (duration < 1 || duration > 3){
        cout << "Invalid duration. Only 1 to 3 months allowed.\n";
        cin.ignore(1000, '\n');
        cin.get();
        return;
    }

    //makePayment(step, currID, name, vehicleNo, startMonth, startYear, duration, "APPLY");

}

/*void renewPass(int &step, string &currID){
    clearScreen();
    loadApplication();
    loadStudent();

    

}*/

/*void makePayment(){


}*/