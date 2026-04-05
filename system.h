#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
using namespace std;

struct Application {                                     // Fields for application.txt
        string appNo, studentID, studentName, status;    // Status are Pending, Approved, Rejected, Expired
        int startMonth;                                  // 1-12
        int startYear;                                   // e.g. 2024
        int duration;                                    // Duration 1-3 months  
};

struct Student {
        string studentID, studentName, password, faculty, phone, vehicleNo, status;
};

struct Payment{
        string paymentID, appNo, studentID, paymentStatus, paymentDate;
        double amount;
};

constexpr int MAX_STUDENT = 100;

extern Application applist[MAX_STUDENT];
extern int appCount;
extern int appNO;

void header (string sub);
void split (void);
int option (string array[], int size);
void invalid (void);

void login (int &step); // Login
void regis (int &step); // Register

void admin_menu(int &step);
void loadApplication();
void saveApplication();
void list_pending_applications(int &step);
void monthEndAlter(int &step);
void studentAuth_menu();

#endif