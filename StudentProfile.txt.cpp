#include <iostream>
using namespace std;

void systemMenu();
void loadStudents();
void loadApplications();
void loadPayments();

int main()
 {
    systemMenu();
    loadStudents();
    loadApplications();
    loadPayments();

    return 0;
}


void systemMenu()
 {
    cout << "System is starting..." << endl;
}

void loadStudents()
 {
    cout << "\nLoading Students..." << endl;

    char name[50];

    cout << "Enter student name: ";
    cin >> name;

    cout << "Student Loaded: " << name << endl;
}

void loadApplications()
 {
    cout << "\nLoading Applications..." << endl;

    char app[50];

    cout << "Enter application name: ";
    cin >> app;

    cout << "Application Loaded: " << app << endl;
}

void loadPayments()
 {
    cout << "\nLoading Payments..." << endl;

    char payment[50];

    cout << "Enter payment info: ";
    cin >> payment;

    cout << "Payment Loaded: " << payment << endl;
}
