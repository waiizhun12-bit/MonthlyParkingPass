#include <iostream>
#include <iomanip>
#include "system.h"
using namespace std;

int admin_dashboard();  

void admin_menu(int &step)   
{
    while (step == -1) {
        int selection = admin_dashboard();   

        switch (selection)
        {
            case 1:
                listPendingApplications(step);
                break;

            case 2:
                verifyPayment(step);
                break;

            case 3:
                generateMonthlyReport(step);
                break;
            
            case 4:
                generateSummaryReport(step);
                break;
                
            case 5:
                step = 0;    // back to main menu
                clearScreen();
                return;

            default:
                invalid();
                break;
        }
    }
}

int admin_dashboard()
{
    int choose;

    cout <<"---------------------------------------"<<endl;
    cout <<"-           ADMIN   DASHBOARD         -"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"- 1. Approve / Reject Applications    -"<<endl;
    cout <<"- 2. Verify Payment                   -"<<endl;
    cout <<"- 3. Generate Monthly Report          -"<<endl;
    cout <<"- 4. Generate Summary Report          -"<<endl;
    cout <<"- 5. Exit                             -"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"Enter your choice: ";

    cin >> choose;
    return choose;
}
