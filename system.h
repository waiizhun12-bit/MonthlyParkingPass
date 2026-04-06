#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
using namespace std;

struct Application {                                     // Fields for application.txt
        string appID, studentID, studentName, status;    // Status are Pending, Approved, Rejected, Expired
        int startMonth;                                  // 1-12
        int startYear;                                   // e.g. 2024
        int duration;                                    // Duration 1-3 months  
};

struct Student {
        string userID, studentID, studentName, email, password, phone, faculty, nric, vehicleNo;
};

struct Payment{
        string paymentID, appID, studentID, paymentStatus, paymentDate;
        double amount;
};

constexpr int MAX_STUDENT = 100;
constexpr int MAX_APPLICATIONS = 200;
constexpr int MAX_PAYMENTS = 200;

extern Application appList[MAX_APPLICATIONS];
extern int appCount;
extern int appNo;

extern Student studentList[MAX_STUDENT];
extern int studentCount;
extern int userNo;

extern Payment payList[MAX_PAYMENTS];
extern int payCount;
extern int payNo;

void header (string sub);
void split (void);
int option (string array[], int size);
void invalid (void);

void login (int &step); // Login
void regis (int &step); // Register

void admin_menu(int &step);                     // Show admin menu
void loadStudent();                             // Load student.txt
void saveStudent();                             // Save student.txt
void loadApplication();                         // Load application.txt
void saveApplication();                         // Save application.txt
void listPendingApplications(int &step);        // Show pending applications
void monthEndAlter(int &step);                  // Show expire passes, and send alert to student
void studentAuthMenu(int &step);                

#endif