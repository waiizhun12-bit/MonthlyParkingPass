#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
using namespace std;

struct Application {                                     // Fields for application.txt
        string appID, studentID, studentName, 
        status, vehicleNo;    
        int startMonth;                                  // 1-12
        int startYear;                                   // e.g. 2024
        int duration;                                    // Duration 1-3 months  
};

struct STUDENT {                                         // Fields for student.txt
        string name, nric, p_num, id, faculty,
        email, password;
};

struct Payment{                                          // Fields for payment.txt
        string paymentID, studentID, 
        paymentStatus, paymentDate;
        double amount;
};

const int MAX_STUDENT = 100;
const int MAX_APPLICATIONS = 200;
const int MAX_PAYMENTS = 200;

extern Application appList[MAX_APPLICATIONS];
extern int appCount;
extern int appNo;

extern STUDENT studentList[MAX_STUDENT];
extern int studentCount;

extern Payment payList[MAX_PAYMENTS];
extern int payCount;
extern int payNo;

extern string currID;

void header (string sub);
void split (void);
int option (string array[], int size);
void invalid (void);
void clearScreen ();

void loadStudent ();
void saveStudent ();
void loadApplication ();
void saveApplication ();
void loadPayment ();
void savePayment ();

void login (int &step, string &currID); // Login
void regis (int &step, string &currID); // Register
int toInteger (const string& s);
string toString (int value);
double toDouble (const string& str);

void admin_menu (int &step);
void generateMonthlyReport (int &step);
void generateSummaryReport (int &step);
void listPendingApplications (int &step);
void verifyPayment (int &step);

void studentMenu (int &step, string &currID);
void passValidityChecker (int &step, string &currID);
void cancelPendingApplication (int &step, string &currID);
void viewTransactionHistory (int &step, string &currID);
void viewStatus (int &step, string &currID);
void applyRenewPasses (int &step, string &currID);
void makePayment (int &step, string &currID, string &name, string &vehicleNo,
                 int startMonth, int startYear, int duration);
void monthEndRenewalAlert (string &currID);

#endif
