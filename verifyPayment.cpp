#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "system.h"
using namespace std;

void verifyPayment(int &step){
	
	while (step == 3) {
	clearScreen();
	loadPayment();
		
		cout << "---------------------------------------------------------------------" << endl;
  		cout << "-                PAYMENT       VERIFICATION        LIST             -" << endl;
    	cout << "---------------------------------------------------------------------" << endl;
		cout <<"| " << setw(10) << left << "Payment ID"
             << " | " << setw(10) << left << "Student ID" 
             <<"  | " << setw(10) << left << "Payment Status"
			 << " | " << setw(8) << left << "Amount"
			 << " | " << setw(12) << left << "Payment Date"
             << " |" << endl;
		cout << "---------------------------------------------------------------------" << endl;

		for (int i = 0; i < payCount; i++){
			if (payList[i].paymentStatus == "PAID" || payList[i].paymentStatus == "UNPAID")
			{
				cout <<"| " << setw(10) << left << payList[i].paymentID
            		 << " | " << setw(10) << left << payList[i].studentID
                	 <<"  | " << setw(15) << left << payList[i].paymentStatus
					 << " | " << setw(8) << left << payList[i].amount
					 << " | " << setw(12) << left << payList[i].paymentDate
                	 << " |" << endl;	
			}
		}
		cout << "---------------------------------------------------------------------" << endl;

        string pid;
		
		do{
			cout << "Enter payment ID (e.g. P1): ";
			cin >> pid;

			if (pid.length() < 2 || pid.length() > 4){
				cout << "Payment ID invalid.\n";
			}
		}while(pid.length() < 2 || pid.length() > 4);
		        
        int paymentAmount[MAX_APPLICATIONS];
		int matchedCount = 0;
		
		for (int i = 0; i < payCount; i++){
			
			if (payList[i].paymentID == pid && 
			   (payList[i].paymentStatus == "PAID" || payList[i].paymentStatus == "UNPAID")){
					
					paymentAmount[matchedCount] = i;
					matchedCount++;
            }
		}

		if (matchedCount == 0){
				cout << "No payment record found for " << pid << "." << endl;
				cout << "Press any button back to admin menu...";
				cin.ignore();
				cin.get();
				return;
		}

		int select;
		cout << "\n1. Confirm payment.\n";
		cout << "2. Cancel verification.\n";
		cout << "3. Back to admin menu.\n";
		cout << "4. Back to payment list.\n";
		
		cout << "Enter your choice: \n";
		cin >> select;
		
		switch(select){
			
			case 1:{ 
				payList[paymentAmount[0]].paymentStatus = "VERIFIED";

				time_t now = time(NULL);
				tm *local = localtime(&now);

				string date = toString(1900 + local ->tm_year) + "-" +
							  (local ->tm_mon + 1 < 10 ? "0" : "") + toString(local->tm_mon + 1) + "-" +
							  (local ->tm_mday < 10 ? "0" : "") + toString(local->tm_mday);

				payList[paymentAmount[0]].paymentDate = date;

				cout <<"\n" << pid << " had verified successfully.\n";
				savePayment();

				cout << "Press Enter back to payment list....";
				cin.ignore();
				cin.get();
				continue;
			}
				
			case 2:{ 
				cout << "Verification cancelled. Payement Status remains."
					 << payList[paymentAmount[0]].paymentStatus << "\n";
				cout << "Press Enter back to payment list....";
				cin.ignore();
				cin.get();
				continue;
			}
			case 3:{
				cout << "Back to admin menu.\n";
				step = 3;
				return;
			}
			case 4:{	
				continue;
			}
			default:{
				cout << "Invalid choice.\n";
                cout << "Press Enter to return to payment list...";
                cin.ignore();
                cin.get();
                continue;
            }
		}
	}
} 
