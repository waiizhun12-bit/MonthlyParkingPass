#include <iostream>
#include "system.h"
using namespace std;

int admin_dashboard();

void admin_menu()
{
    int selection;
    selection = admin_dashboard();
}
int admin_dashboard()
{ 
    int choice;

    cout <<"---------------------------------------"<<endl;
    cout <<"-           ADMIN   DASHBOARD         -"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"- 1. List Pending Applications        -"<<endl;
    cout <<"- 2. Approve / Reject Applications    -"<<endl;
    cout <<"- 3. Generate Monthly Report          -"<<endl;
    cout <<"- 4. View Month-End Alerts            -"<<endl;
    cout <<"- 5. Manage Students                  -"<<endl;
    cout <<"- 6. Logout                           -"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"Enter your choice: ";

    cin >>choice;
    return choice;
}