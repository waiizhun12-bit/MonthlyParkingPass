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
        cout << "4. Apply/Renew Passport                                            -"<< endl;
        cout << "5. Check Passport Validity                                         -"<< endl;
        cout << "6. View / Cancel Pending Application                               -"<< endl;
        cout << "7. Make Payment                                                    -"<< endl;
        cout << "8. View Transaction History                                        -"<< endl;
        cout << "0. Logout                                                          -"<< endl;
        cout << "--------------------------------------------------------------------" << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                    //viewProfile(); 
                    break;

            case 2: 
                    //updateProfile(); 
                    break;

            case 3:
                   // resetPasswordStudent(); 
                    break;

            case 4: 
                    //applyRenewPass(); 
                    break;

            case 5: 
                    //passValidityChecker(); 
                    break;

            case 6: 
                    viewStatus(step, currID); 
                    //cancelPendingApplication();
                        break;
                
            case 7: 
                    //makePayment(); 
                    //generateReceipt(); 
                    break;

            case 8: 
                   // viewTransactionHistory(); 
                   // filterTransactionHistory(); 
                    break;

            case 0: 
                    cout << "Logging out to main menu...\n"; 
                    step = 0;
                    break;

            default: invalid();
        }
    }
  
}