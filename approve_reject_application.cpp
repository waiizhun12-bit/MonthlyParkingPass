#include<iostream>
#include "system.h"
using namespace std;


int approve_application();

void approve_reject_application()
{
    int pilihan;
    cout <<"---------------------------------------"<<endl;
    cout <<"-     APPROVE / REJECT APPLICATIONS   -"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"- 1. Approve Application              -"<<endl;
    cout <<"- 2. Reject Application               -"<<endl;
    cout <<"- 3. Back to Dashboard                -"<<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"Enter your choice: ";

    cin >> pilihan;
    cin.ignore(); // To ignore the newline character left by cin

    pilihan = approve_application();
}

int approve_application(){
    cout <<"Approving application..."<<endl;
    // Implement the logic to approve the application here
    return 0;
}