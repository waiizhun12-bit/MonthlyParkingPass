#include <iostream>
#include <string>
#include "system.h" 
using namespace std;

void viewProfile();
void updateProfile();
void resetPasswordStudent();
void applyRenewPass();
void passValidityChecker();
void renewPass();
void cancelPendingApplication();
void viewApplicationStatus();
void makePayment();
void generateReceipt();
void viewTransactionHistory();
void filterTransactionHistory();
void showMonthEndRenewalAlert();


void studentMenu(int &step, string &currStudentID) {
    int choice;

        cout << "\n===== Student Main Menu =====\n";
        cout << "1. View Profile\n";
        cout << "2. Update Profile\n";
        cout << "3. Reset Password\n";
        cout << "4. Apply/Renew Passport\n";
        cout << "5. Check Passport Validity\n";
        cout << "6. Renew Passport\n";
        cout << "7. Cancel Pending Application\n";
        cout << "8. View Application Status\n";
        cout << "9. Make Payment\n";
        cout << "10. View Transaction History\n";
        cout << "11. Show Month-End Renewal Alert\n";
        cout << "0. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                    viewProfile(); 
                    break;

            case 2: 
                    updateProfile(); 
                    break;

            case 3:
                    resetPasswordStudent(); 
                    break;

            case 4: 
                    applyRenewPass(); 
                    break;

            case 5: 
                    passValidityChecker(); 
                    break;
            case 6: 
                    renewPass(); 
                    break;

            case 7: 
                    cancelPendingApplication();
                    break;

            case 8: 
                    viewApplicationStatus(); 
                    break;

            case 9: 
                    makePayment(); 
                    generateReceipt(); 
                    break;

            case 10: 
                    viewTransactionHistory(); 
                    filterTransactionHistory(); 
                    break;

            case 11: 
                    monthlyAlertStudent (step, currStudentID); 
                    break;

            case 0: 
                    cout << "Logging out to main menu...\n"; 
                    step = 0;
                    break;

            default: invalid();
        }
}


void viewProfile() { 
    cout << "Viewing profile...\n"; }
void updateProfile() { 
    cout << "Updating profile...\n"; }
void resetPasswordStudent() { 
    cout << "Resetting password...\n"; }
void applyRenewPass() { 
    cout << "Applying/Renewing passport...\n"; }
void passValidityChecker() { 
    cout << "Checking passport validity...\n"; }
void renewPass() { 
    cout << "Renewing passport...\n"; }
void cancelPendingApplication() { 
    cout << "Cancelling pending application...\n"; }
void viewApplicationStatus() { 
    cout << "Viewing application status...\n"; }
void makePayment() { 
    cout << "Making payment...\n"; }
void generateReceipt() {
     cout << "Generating receipt...\n"; }
void viewTransactionHistory() { 
    cout << "Viewing transaction history...\n"; }
void filterTransactionHistory() { 
    cout << "Filtering transaction history...\n"; }
void showMonthEndRenewalAlert() { 
    cout << "Showing month-end renewal alert...\n"; }
