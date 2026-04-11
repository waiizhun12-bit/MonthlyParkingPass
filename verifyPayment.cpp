#include <iostream>
#include <ctime>
#include <iomanip>
#include "system.h"
using namespace std;

void verifyPayment(int &step){
			loadPayment();
		
					cout << "---------------------------------------------------------------" << endl;
  					cout << "-            PAYMENT      VERIFICATION       LIST             -" << endl;
    				cout << "---------------------------------------------------------------" << endl;
					cout <<"| " << setw(5) << left << "Payment ID"
            			 << " | " << setw(14) << left << "Student ID" 
                		 <<"  | " << setw(10) << left << "Payment Status"
						 << " | " << setw(8) << left << "Amount"
						 << " | " << setw(10) << left << "Payment Date"
                		 << " |" << endl;
					cout << "---------------------------------------------------------------" << endl;

		for (int i = 0; i < payCount; i++){
			if (payList[i].paymentStatus == "Paid" || payList[i].paymentStatus == "UNPAID")
			{
				cout <<"| " << setw(5) << left << payList[i].paymentID
            			 << " | " << setw(14) << left << payList[i].studentID
                		 <<"  | " << setw(10) << left << payList[i].paymentStatus
						 << " | " << setw(8) << left << payList[i].amount
						 << " | " << setw(10) << left << payList[i].paymentDate
                		 << " |" << endl;	
			}
		}
				cout << "---------------------------------------------------------------" << endl;
                
        string pid;
		
		do{
			cout << "Enter payment ID (P1): ";
			cin >> pid;
		}while(pid.empty());
		        
        int paymentAmount[payCount];
		int payCount = 0;
		
		for (int i = 0; i < payCount; i++){
			
			if (payList[i].paymentID == pid && payList[i].paymentStatus == "Paid" || payList[i].paymentStatus == "Unpaid"){
					
					paymentAmount[payCount] = i;
					payCount++;
            }
            
            if (payList[i].paymentID != pid){
            	cout << "\nInvalivd Payment ID, Please enter again: ";
			}
			
			if (payCount == 0){
				cout << "No payment record found for " << pid << "." << endl;
				return;
			}
		}
		
		int select;
		cout << "1. Confirm payment.\n";
		cout << "2. Cancel.\n";
		cout << "3. Back.\n";
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

				payList[paymentAmount[0]].paymentDate;
				cout <<"\n" << pid << "had verified successfully.\n";
				savePayment();
				break;
			}
				
			case 2:{ 
				payList[paymentAmount[0]].paymentStatus = "UNVERIFIED";
				cout << "Your payment status still UNPAID.";
				savePayment();
				break;
			}

			default:{
				step = 3;
				cout << "Back to admin menu.";
				return;
			}
		}
		return;	
	} 