#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
using namespace std;


int login_register();
int login_menu();
int register_menu();
int reset_password();

int main (){
    
    int answer, fpassword;
    answer = login_register();

    while(answer < 1 || answer > 2)
    {
        cout <<"Please enter again: ";
        cin >>answer;
    }
    
    if(answer == 1)
    {   
        cout <<register_menu();

    }else if(answer == 2){

        login_menu();
        cout <<"Forgot password (1)";
        cin >>fpassword;
        while(fpassword < 1 || fpassword > 1)
        {
            cout <<"Please enter again: ";
            cin >>fpassword;
        }
    }

    return 0;
}

int login_register()
{
    int choice;

    cout <<"---------------------- \n";
    cout <<"| Student       Menu | \n";
    cout <<"----------------------"<<endl;

    cout <<"--------------------- \n";
    cout <<"| Register Menu (1) |\n";
    cout <<"| Login    Menu (2) |\n";
    cout <<"--------------------- \n";

    cin>>choice;

    return choice;
}   

int login_menu()
{
    cout <<"------------------- \n";
    cout <<"| Login      Menu | \n";
    cout <<"-------------------"<<endl;

    string id, ps;
    do{
        cout <<"Student ID: \n";
        getline(cin, id);
        if(id.empty()) cout <<"ID cannot be empty, please enter again: ";
        
    }while(id.length() != 7 || id.empty());
        cout <<"Your ID is not valid, please enter again: ";
        cin >>id;

    do{
        cout <<"Password  : \n";
        getline(cin, ps);     
    }while (ps.length() <= 5 || ps.length() >= 20);
         cout <<"Password should be between 6 and 20 characters, please enter again: ";
         cin >>ps;

         return 0;
}

int register_menu()
{
    int faculty_choice;
    string name, password, faculty, email, vehicle_plate, vehicle_type, student_id;

    cout <<"------------------- \n";
    cout <<"| Register   Menu | \n";
    cout <<"-------------------"<< endl;

    //StudentID
    while (true) {
        cout <<"Student ID (e.g., 2101234): ";
        cin >> student_id;
        if (student_id.length() == 7) {
            string prefix = student_id.substr(0, 2);
            if (prefix >= "21" && prefix <= "25") break;
        }
        cout <<"Invalid! Must start with 21-25 and be 7 digits long.\n";
    }

    // Clear the buffer to allow getline to work correctly after cin >>
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Name
    do {
        cout <<"Name          : ";
        getline(cin, name);
        if (name.empty()) cout <<"Name cannot be empty!\n";
    } while (name.empty());

    //Password 
    while(true){
        cout <<"Password      : ";
        cin >>password;
        if (password.length() >= 6 && password.length() <=19)break;
        cout <<"Password must be between 6 and 19 characters!\n";
      }

        
    //Faculty 
    while (true) {
        cout <<"\nSelect Faculty:\n1.MKF MAHS  2.LKCFES  3.FEGT  4.FICT  5.FOS\n";
        cout <<"6.FAM       7.FCI     8.FCS   9.FE    10.CFS\nChoice: ";

        if (cin >>faculty_choice && faculty_choice >= 1 && faculty_choice <= 10) {
            string list[] = {"MKF MAHS", "LKCFES", "FEGT", "FICT", "FOS", "FAM", "FCI", "FCS", "FE", "CFS"};
            faculty = list[faculty_choice - 1];
            break;
        }
        cout <<"Invalid choice! Enter 1-10.\n";
        cin.clear(); cin.ignore(1000, '\n');
    }

    //Email
    string domain = "@1utar.my";
    while (true) {
        cout <<"Email (must end with @1utar.my): ";
        cin >>email;
        if (email.length() > domain.length() && 
            email.substr(email.length() - domain.length()) == domain) break;
        cout <<"Invalid email! Use your student email format.\n";
    }

    //Vehicle Info
    cout <<"Vehicle Plate : ";
    cin >>vehicle_plate;

    //Vehicle Type
    cout <<"Vehicle Type  : ";
    cin.ignore();
    getline(cin, vehicle_type);

    cout << "\nRegistration Successful for " << name << "!" << endl;
    return 0;
}