/*#include <iostream>
#include <iomanip>
#include <ctime>
#include "system.h"
using namespace std;

bool findLargestApprovePast(const string& sid) {
    bool found = false;

    for (int i = 0; i< appCount; i++){
        if (applist[i].studentID == sid && applist[i].status == "Approved") {
            if(!found){
                latest = applist[i];
                found = true;
            } else if(applist[i].startYear > latest.startYear || 
                (applist[i].startYear == latest.startYear && applist[i].startMonth > latest.startMonth)) {
                latest = applist[i];
            }
            break;
        }
        return found;
    }
}

void reminder(const string& sid) {
    // Get current date
    time_t now = time(0);
    tm* now = localtime(&t);
    int curDay = now->tm_mday;
    int curMonth = now->tm_mon + 1; // tm_mon is 0-11
    int curYear = now->tm_year + 2020; // tm_year is years
    
    Application latest;
    if (!findLargestApprovePast(sid, latest))
    {
        cout << "No approved applications found for this student." << endl;
        cout << "Tip: Apply / Renew your parking pass." << endl;
        return;
    }
}
    */