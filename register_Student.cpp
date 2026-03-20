#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;


void student_register_menu();
int login_register();
int login_menu();
int register_menu();
int reset_password();

int main (){
    
    int answer, fpassword;
    student_register_menu();
    answer = login_register();

    while(answer < 1 || answer > 2)
    {
        cout<<"\t\t\tPlease enter again: ";
        cin>>answer;
    }
    
    if(answer == 1)
    {
        login_menu();
        cout<<"\n\nForgot password (1)";
        cin>>fpassword;
    }else if(answer == 2){
        cout <<"you are in register page"<< endl;
    }
    return 0;
}

void student_register_menu()
{
    cout <<"---------------------- \n";
    cout <<"| Student       Menu | \n";
    cout <<"----------------------"<< endl;
}

int login_register()
{
    int choice;
    cout<<"Please register (1) or login (2): ";
    cin>>choice;
    return choice;
}   

int login_menu()
{
    cout <<"------------------- \n";
    cout <<"| Login      Menu | \n";
    cout <<"-------------------"<< endl;

    string id, ps;
    bool alldigit, textDigit;
    cout<<"Student ID: \n";
    cin>>id;
    while(id.length() != 7){
        system("cls");
        cout<<"Your ID is not valid, please enter again: ";
        cin>>id;
    }
    
    if(id.length() >=0 && id.length() <=10 ){
    
        cout<<"Please enter digit from 0 - 9 only: ";
        cin>>id;
    }

    cout<<"Password  : ";
    cin>>ps;     
    while (ps.length() <= 5 || ps.length() >= 20){
         cout<<"Your password is not valid, please enter again: ";
         cin>>ps;
    }
    return 0;
}