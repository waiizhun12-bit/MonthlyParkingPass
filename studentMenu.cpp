#include <iostream>
#include <string>
#include "system.h" 
using namespace std;

void studentMenu(int &step, string &currID) {
    
    while (step == 3){  
        clearScreen();
        int choice;

        cout << "--------------------------------------------------------------------" << endl;
        cout << "-                      STUDENT        MENU                         -" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "1. View Profile                                                    -"<< endl;
        cout << "2. Update Profile                                                  -"<< endl;
        cout << "3. Reset Password                                                  -"<< endl;
        cout << "4. Apply / Renew Parking Pass                                      -"<< endl;
        cout << "5. Check Pass Validity                                             -"<< endl;
        cout << "6. View Application Status                                         -"<< endl;
        cout << "7. Cancel Pending Application                                      -"<< endl;
        cout << "8. View Transaction History                                        -"<< endl;
        cout << "0. Logout                                                          -"<< endl;
        cout << "--------------------------------------------------------------------" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
                case 1: 
                        viewProfile(step, currID); 
                        break;
                case 2: 
                        updateProfile(step,currID); 
                        break;

                case 3:
                        resetPassword(step, currID); 
                        break;

                case 4: 
                        applyRenewPasses(step, currID); 
                        break;

                case 5: 
                        passValidityChecker(step, currID); 
                        break;

                case 6: 
                        viewStatus(step, currID); 
                        break;

                case 7: 
                        cancelPendingApplication(step, currID);
                        break;

                case 8:
                        viewTransactionHistory(step, currID); 
                        break;

                case 0: 
                        cout << "Logging out to main menu...\n"; 
                        step = 0;
                        clearScreen();
                        break;

                default: invalid();
        }
    }
  
}