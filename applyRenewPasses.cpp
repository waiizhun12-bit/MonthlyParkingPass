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
#include <ctime>
#include "system.h"
using namespace std;

void applyPass(int &step, string &currID);
void renewPass(int &step, string &currID);
void makePayment(int &step, string &currID, string &name, string &vehicleNo,
                 int startMonth, int startYear, int duration);

void applyRenewPasses(int &step, string &currID){
   
    while (step == 3){
        clearScreen();
        loadApplication();

        int choice;
        cout << "1. Apply Month Parking Pass" << endl;
        cout << "2. Renew Pass" << endl;
        cout << "3. Exit" << endl; 
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            applyPass(step, currID);
            break;

        case 2:
            renewPass(step, currID);
            break;
        
        case 3:
            return;

        default:
            invalid();
    }
    }
}

void applyPass(int &step, string &currID){
    clearScreen();
    loadStudent();
    loadApplication();

    string name, vehicleNo;
    int startMonth, startYear, duration;

    time_t t = time(NULL);
    tm *now = localtime(&t);
    int currentYear = now->tm_year + 1900;

    cout << "---------------------------------------------------------------------" << endl;
    cout << "-                          APPLY NEW PASS                           -" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "- Student ID: " << currID << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "- Enter student name: ";
    getline(cin, name);

    do{
        cout << "- Enter vehicle no   : ";
        getline(cin, vehicleNo);

        if(vehicleNo.empty()){
            cout << "Vehicle number cannot be empty!" << endl;
        }
    }while(vehicleNo.empty());

    do{
        cout << "- Enter start month (1-12): " << endl;
        cin >> startMonth;

        if (startMonth < 1 || startMonth > 12){
           cout << "Ivalid input, please select between (1-12) only: "<< endl;
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while(startMonth < 1 || startMonth > 12);

    do{
        cout << "- Enter start year        : ";
        cin >> startYear;

        if (startYear < currentYear || startYear > currentYear + 1) {
            cout << "Invalid start year. Only " << currentYear
                << " or " << currentYear + 1 << " allowed.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (startYear < currentYear || startYear > currentYear + 1);

    do{
        cout << "- Enter duration (1-3)    : ";
        cin >> duration;

        if (duration < 1 || duration > 3){
            cout << "Invalid duration. Only 1 to 3 months allowed.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while(duration < 1 || duration > 3);

    makePayment(step, currID, name, vehicleNo, startMonth, startYear, duration);

    return;
}

void renewPass(int &step, string &currID){
    clearScreen();
    loadApplication();
    loadStudent();

    string name = "";
    string vehicleNo;
    int startMonth, startYear, duration;
    bool foundStudent = false;
    bool hasApproved = false;

    time_t t = time(NULL);
    tm *now = localtime(&t);
    int currentYear = now->tm_year + 1900;

    for (int i = 0; i < studentCount; i++){
        if (studentList[i].id == currID){
            name = studentList[i].name;
            foundStudent = true;
            break;
        }
    }

    if (!foundStudent){
        cout << "Student record not found.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    for (int i = 0; i < appCount; i++){
        if (appList[i].studentID == currID && appList[i].status == "APPROVED"){
            hasApproved = true;
            break;
        }
    }

    if (!hasApproved){
        cout << "You do not have any approved pass to renew.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    cout << "---------------------------------------------------------------------" << endl;
    cout << "-                            RENEW    PASS                          -" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Student ID   : " << currID << endl;
    cout << "Student Name : " << name << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do{
        cout << "- Enter vehicle no   : ";
        getline(cin, vehicleNo);

        if(vehicleNo.empty()){
            cout << "Vehicle number cannot be empty!" << endl;
        }
    }while(vehicleNo.empty());
// here continue
    do{
        cout << "Enter start month (1-12): ";
        cin >> startMonth;

        if (startMonth < 1 || startMonth > 12){
           invalid();
        }
    }while(startMonth < 1 || startMonth > 12);

    do{
        cout << "- Enter start year        : ";
        cin >> startYear;

        if (startYear < currentYear || startYear > currentYear + 1) {
            cout << "Invalid start year. Only " << currentYear
                << " or " << currentYear + 1 << " allowed.\n";
        }
    } while (startYear < currentYear || startYear > currentYear + 1);

    do{
        cout << "- Enter duration (1-3)    : ";
        cin >> duration;

        if (duration < 1 || duration > 3){
            cout << "Invalid duration. Only 1 to 3 months allowed.\n";
        }
    }while(duration < 1 || duration > 3);

    makePayment(step, currID, name, vehicleNo, startMonth, startYear, duration);

    return;
}

void makePayment(int &step, string &currID, string &name, string &vehicleNo,
                 int startMonth, int startYear, int duration){
    clearScreen();
    loadApplication();
    loadPayment();

    double total = duration * 50;
    int payChoice;
    string payMethod = "";

    int choice;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "-                           PAYMENT     PAGE                        -" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Month: " << startMonth << endl;
    cout << "Vehicle Number: " << vehicleNo << endl;
    cout << "Year: " << startYear << endl;
    cout << "Duration: " << duration << endl;
    cout << "Total: RM " << total << endl;
    cout << "---------------------------------------------------------------------" << endl;
    
    cout << "Select payment method: " << endl;
    cout << "1. Online Banking" << endl;
    cout << "2. Touch 'n Go" << endl;
    cout << "3. Debit / Credit Card" << endl;
    cout << "0. Cancel Payment" << endl;
    cout << "Enter your choice: " << endl;
    cin >> payChoice;

    switch (payChoice){
        case 1:
            payMethod = "ONLINE BANKING";
            break;
        case 2:
            payMethod = "TOUCH N GO";
            break;
        case 3:
            payMethod = "CARD";
            break;
        case 0:
            cout << "Payment cancelled.\n";
            cin.ignore(1000, '\n');
            cin.get();
            return;
        default:
            invalid();
            return;
    }

    time_t now = time(NULL);
    tm *local = localtime(&now);

    string date = toString(1900 + local->tm_year) + "-" +
              (local->tm_mon + 1 < 10 ? "0" : "") + toString(local->tm_mon + 1) + "-" +
              (local->tm_mday < 10 ? "0" : "") + toString(local->tm_mday);
    
              // save application
    appNo++;
    appList[appCount].appID = toString(appNo);
    appList[appCount].studentID = currID;
    appList[appCount].studentName = name;
    appList[appCount].vehicleNo = vehicleNo;
    appList[appCount].status = "PENDING";
    appList[appCount].startMonth = startMonth;
    appList[appCount].startYear = startYear;
    appList[appCount].duration = duration;
    appCount++;

    // save payment
    payNo++;
    payList[payCount].paymentID = toString(payNo);
    payList[payCount].studentID = currID;
    payList[payCount].paymentStatus = "PAID";
    payList[payCount].amount = total;
    payList[payCount].paymentDate = date; // date
    payCount++;

    saveApplication();
    savePayment();

    cout << "Payment successfully with " << "RM " << total << endl; 
    cout << "Press Enter...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}