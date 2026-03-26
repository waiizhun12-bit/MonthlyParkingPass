#include <iostream>
#include <iomanip>
#include "system.h"
using namespace std;

int admin_dashboard();

void admin_menu()
{
    int selection;
    selection = admin_dashboard();

    switch (selection)
    {
    case 1:
        list_pending_applications();
        break;

    default:
        break;
    }
}
int admin_dashboard()
{ 
    int choose;

    cout <<"---------------------------------------"<<endl;
    cout <<"-           ADMIN   DASHBOARD         -"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<setw(30) << left << "- 1. Approve & Reject Applications    -"<<endl;
    cout <<setw(30) << left << "- 2. Generate Monthly Report          -"<<endl;
    cout <<setw(30) << left << "- 3. View Application Statistics      -"<<endl;
    cout <<setw(30) << left << "- 4. Manage Users                     -"<<endl;
    cout <<setw(30) << left << "- 5. Exit                             -"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"Enter your choice: ";

    cin >>choose;
    return choose;
}