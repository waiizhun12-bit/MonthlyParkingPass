#include <iostream>
#include <iomanip>
#include "system.h"
using namespace std;

int admin_dashboard();  

void admin_menu(int &step)   
{
    while (step == 3) {
        int selection = admin_dashboard();   

        switch (selection)
        {
            case 1:
                listPendingApplications(step);
                break;

            case 3:
                monthEndAlter(step);
                break;
            case 5:
                step = 0;    // back to main menu
                return;

            default:
                cout << "Invalid choice.\n";
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
    cout <<"- 1. Approve & Reject Applications    -"<<endl;
    cout <<"- 2. Generate Monthly Report          -"<<endl;
    cout <<"- 3. Month End Alert                  -"<<endl;
    cout <<"- 4. Manage Students                  -"<<endl;
    cout <<"- 5. Exit                             -"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"Enter your choice: ";

    cin >> choose;
    return choose;
}