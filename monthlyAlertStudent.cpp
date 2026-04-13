#include <iostream>
#include <sstream>
#include "system.h"

using namespace std;

void monthlyAlertStudent (){
        clearScreen();
        loadApplication();

        time_t t = time(NULL);                   // Get the current time (in second)
        tm *now = localtime(&t);                 // Convert time to date
        int curMonth = now-> tm_mon + 1;        
        int curYear = now-> tm_year + 1900;

        for (int i = 0; i < studentCount; i++){
            stringstream ss;
            getline(ss, studentList[studentCount].studentID);
            cout << studentList[studentCount].studentID << endl;
        }
}