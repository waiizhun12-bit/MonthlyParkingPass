#include <iostream>
#include <iomanip>
#include <limits>
#include "system.h"
using namespace std;

void generateMonthlyReport(int &step){
    clearScreen();
    loadApplication();
    loadPayment();

    int month, year;
    int totalApplications = 0;
    int approved = 0, pending = 0, rejected = 0;
    int paid = 0, unpaid = 0;

    cout << "---------------------------------------------------------------------" << endl;
    cout << "-                       GENERATE MONTHLY REPORT                     -"<< endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    for (int i = 0; i < appCount; i++){
        if (appList[i].startMonth == month && appList[i].startYear == year){
            totalApplications++;

            if (appList[i].status == "APPROVED")
                approved++;
            else if (appList[i].status == "PENDING")
                pending++;
            else if (appList[i].status == "REJECTED")
                rejected++;
        }
    }

    for (int i = 0; i < payCount; i++){
        // simple payment monthly check by payment date string: YYYY-MM-DD
        if (payList[i].paymentDate.size() >= 7){
            string yearStr = payList[i].paymentDate.substr(0, 4);
            string monthStr = payList[i].paymentDate.substr(5, 2);

            int payYear = toInteger(yearStr);
            int payMonth = toInteger(monthStr);

            if (payYear == year && payMonth == month){
                if (payList[i].paymentStatus == "PAID" || payList[i].paymentStatus == "VERIFIED")
                    paid++;
                else if (payList[i].paymentStatus == "UNPAID")
                    unpaid++;
            }
        }
    }

    cout << "---------------------------------------------------------------------" << endl;
    cout << "-                          MONTHLY    REPORT                        -" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Month / Year         : " << month << "/" << year << endl;
    cout << "Total Applications   : " << totalApplications << endl;
    cout << "Approved             : " << approved << endl;
    cout << "Pending              : " << pending << endl;
    cout << "Rejected             : " << rejected << endl;
    cout << "Paid Passes          : " << paid << endl;
    cout << "Unpaid Passes        : " << unpaid << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "Press Enter to continue...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}