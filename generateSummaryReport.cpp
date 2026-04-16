#include <iostream>
#include <iomanip>
#include <limits>
#include "system.h"
using namespace std;

void generateSummaryReport(int &step){
    clearScreen();
    loadApplication();
    loadPayment();

    const int TOTAL_PARK_SPACES = 1000;   

    int totalApplications = 0;
    int approved = 0;
    int pending = 0;
    int rejected = 0;

    int paid = 0;
    int unpaid = 0;
    int verified = 0;

    for (int i = 0; i < appCount; i++){
        totalApplications++;

        if (appList[i].status == "APPROVED")
            approved++;
        else if (appList[i].status == "PENDING")
            pending++;
        else if (appList[i].status == "REJECTED")
            rejected++;
    }

    for (int i = 0; i < payCount; i++){
        if (payList[i].paymentStatus == "PAID")
            paid++;
        else if (payList[i].paymentStatus == "UNPAID")
            unpaid++;
        else if (payList[i].paymentStatus == "VERIFIED")
            verified++;
    }

    double utilizationRate = 0.0;

    if (TOTAL_PARK_SPACES > 0){
        utilizationRate = (double)approved / TOTAL_PARK_SPACES * 100;
    }

    cout << "---------------------------------------------------------------------" << endl;
    cout << "-                          SUMMARY     REPORT                       -" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Total Applications    : " << totalApplications << endl;
    cout << "Approved Applications : " << approved << endl;
    cout << "Pending Applications  : " << pending << endl;
    cout << "Rejected Applications : " << rejected << endl;
    cout << "Paid Payments         : " << paid << endl;
    cout << "Unpaid Payments       : " << unpaid << endl;
    cout << "Verified Payments     : " << verified << endl;
    cout << "Car Park Utilization  : " << fixed << setprecision(2)
         << utilizationRate << "%" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "Press Enter to continue...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}