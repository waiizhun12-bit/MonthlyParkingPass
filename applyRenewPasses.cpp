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

    // Check whether this user got pass or not. To check this i use "PENDING" and "APPROVED" to scan the text file.
    bool foundPass = false;

    for (int i = 0; i < appCount; i++){

        if (appList[i].studentID == currID && 
            (appList[i].status == "PENDING" || appList[i].status == "APPROVED"))
        {
            foundPass = true;
            break;
        }
    }

    if (foundPass){
        cout << "You already have an existing pass application." << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

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
        cout << "- Enter start month (1-12): ";
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
    
    // after key in all the details, save to application.txt.
    appNo++;
    appList[appCount].appID = "A" + toString(appNo);
    appList[appCount].studentID = currID;
    appList[appCount].studentName = name;
    appList[appCount].vehicleNo = vehicleNo;
    appList[appCount].status = "PENDING";
    appList[appCount].startMonth = startMonth;
    appList[appCount].startYear = startYear;
    appList[appCount].duration = duration;
    appCount++;

    saveApplication();
    return;
}

void renewPass(int &step, string &currID){
    clearScreen();
    loadApplication();
    loadStudent();

    // Check this user got pass stil "PENDING" or not if yes back to student menu
    bool pendingPass = false;

    for (int i = 0; i < appCount; i++){

        if (appList[i].studentID == currID && appList[i].status == "PENDING"){
            pendingPass = true;
            break;
        }
    }

    if (pendingPass){
        cout << "You already have a pending application." << endl;
        cout << "Please wait for the admin review first." << endl;
        return;
    }

    string name = "";
    string vehicleNo;
    int startMonth, startYear, duration;

    bool hasApproved = false;
    bool expired = false;

    time_t t = time(NULL);
    tm *now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;

    // Avoid "APPROVED" but still want renew their pass
    for (int i = 0; i < appCount; i++){
        if (appList[i].studentID == currID && appList[i].status == "APPROVED"){
            hasApproved = true;
            
            int endMonth = appList[i].startMonth + appList[i].duration - 1;         // Example: end month = 5(month) + 2(duration) - 1 = 6
            int endYear = appList[i].startYear;

            while (endMonth > 12){          
                endMonth -= 12;             // if the end month is 13, then 13 - 12 = 1
                endYear++;                  // then year will plus 1 since already 12 months.
            }

            if (currentYear > endYear || 
               (currentYear == endYear && currentMonth > endMonth)){
                expired = true;
            }
        }
    }

    if (!hasApproved){
        cout << "You do not have any approved pass to renew.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

     if (!expired){
        cout << "Your current pass is still active." << endl;
        cout << "You can only renew after it has expired." << endl;
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
        }
    } while (startYear < currentYear || startYear > currentYear + 1);

    do{
        cout << "- Enter duration (1-3)    : ";
        cin >> duration;

        if (duration < 1 || duration > 3){
            cout << "Invalid duration. Only 1 to 3 months allowed.\n";
        }
    }while(duration < 1 || duration > 3);

    appNo++;
    appList[appCount].appID = "A" + toString(appNo);
    appList[appCount].studentID = currID;
    appList[appCount].studentName = name;
    appList[appCount].vehicleNo = vehicleNo;
    appList[appCount].status = "PENDING";
    appList[appCount].startMonth = startMonth;
    appList[appCount].startYear = startYear;
    appList[appCount].duration = duration;
    appCount++;

    saveApplication();

    cout << "Renew pass application submitted successfully." << endl;
    cout << "Please wait for admin approval." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
