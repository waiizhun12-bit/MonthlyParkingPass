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
        string studentID, studentName, email, password, phone, faculty, nric, vehicleNo;
};

struct Payment{
        string paymentID, studentID, paymentStatus, paymentDate;
        double amount;
};

const int MAX_STUDENT = 100;
const int MAX_APPLICATIONS = 200;
const int MAX_PAYMENTS = 200;

extern Application appList[MAX_APPLICATIONS];
extern int appCount;
extern int appNo;

extern Student studentList[MAX_STUDENT];
extern int studentCount;

extern Payment payList[MAX_PAYMENTS];
extern int payCount;
extern int payNo;

extern string currStudentID;

void header (string sub);
void split (void);
int option (string array[], int size);
void invalid (void);
void clearScreen();

void login (int &step, string &currStudentID); // Login
void regis (int &step); // Register
int toInteger(const string& s);
string toString(int value);
double toDouble(const string& str);

void admin_menu(int &step);
void loadStudent();
void saveStudent();
void loadApplication();
void saveApplication();
void loadPayment();
void savePayment();
void listPendingApplications(int &step);
void monthEndAlter(int &step);
void studentMenu (int &step, string &currStudentID);
void verifyPayment(int &step);
void monthlyAlertStudent (int &step, string &currStudentID);
//void manageStudent();



#endif
