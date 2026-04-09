#include <iostream>
#include <string>
using namespace std;

class studentMenu {
private:
    string studentID;
    string name;
    string password;

    string transactionHistory[100];
    int transactionCount;

public:
    studentMenu(string id, string n, string pass) {
        studentID = id;
        name = n;
        password = pass;
        transactionCount = 0;
    }

    void viewProfile() {
        cout << "\n--- Profile ---\n";
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
    }

    void updateProfile() {
        cout << "\nEnter new name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Profile updated!\n";
    }

    bool passValidityChecker(string newPass) {
        return newPass.length() >= 6;
    }

    void apply_renewPass() {
        string newPass;
        cout << "\nEnter new password: ";
        cin >> newPass;

        if (passValidityChecker(newPass)) {
            password = newPass;
            cout << "Password updated successfully!\n";
        } else {
            cout << "Password must be at least 6 characters!\n";
        }
    }

    void viewApplication() {
        cout << "\nViewing applications...\n";
    }

    void cancelPendingApplication() {
        cout << "\nPending application cancelled.\n";
    }

    void generateReceipt(double amount) {
        cout << "\n--- Receipt ---\n";
        cout << "Amount Paid: RM " << amount << endl;
        cout << "Status: PAID\n";
    }

    void makePayment() {
        double amount;
        cout << "\nEnter payment amount: RM ";
        cin >> amount;

        if (transactionCount < 100) {
            transactionHistory[transactionCount] = "Paid RM " + to_string(amount);
            transactionCount++;
        }

        generateReceipt(amount);
    }

    void showTransactionHistory() {
        cout << "\n--- Transaction History ---\n";
        for (int i = 0; i < transactionCount; i++) {
            cout << transactionHistory[i] << endl;
        }
    }

    void filterHistory() {
        cout << "\nFilter (demo)\n";
        showTransactionHistory();
    }
};

int main() {
    studentMenu student("S001", "Ken", "123456");

    int mainChoice, subChoice;

    do {
        
        cout << "\n----------------------------------\n";
        cout << "        STUDENT DASHBOARD         \n";
        cout << "----------------------------------\n";
        cout << "1. Approve & Reject (Application)\n";
        cout << "2. Generate Monthly (Payment)\n";
        cout << "3. Month End Alert (History)\n";
        cout << "4. Full Student Menu\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        switch (mainChoice) {

        case 1:
            student.viewApplication();
            student.cancelPendingApplication();
            break;

        case 2:
            student.makePayment();
            break;

        case 3:
            student.showTransactionHistory();
            break;

        case 4:
        
            do {
                cout << "\n===== Student Menu =====\n";
                cout << "1. View Profile\n";
                cout << "2. Update Profile\n";
                cout << "3. Change Password\n";
                cout << "4. View Application\n";
                cout << "5. Cancel Application\n";
                cout << "6. Make Payment\n";
                cout << "7. Transaction History\n";
                cout << "8. Filter History\n";
                cout << "0. Back\n";
                cout << "Enter choice: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: student.viewProfile(); break;
                case 2: student.updateProfile(); break;
                case 3: student.apply_renewPass(); break;
                case 4: student.viewApplication(); break;
                case 5: student.cancelPendingApplication(); break;
                case 6: student.makePayment(); break;
                case 7: student.showTransactionHistory(); break;
                case 8: student.filterHistory(); break;
                }

            } while (subChoice != 0);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (mainChoice != 0);

    return 0;
}