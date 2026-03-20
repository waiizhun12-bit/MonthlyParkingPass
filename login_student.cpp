#include <iostream>
using namespace std;

int main() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Here you would typically check the username and password against a database
    if (username == "student" && password == "password123") {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password." << endl;
    }

    return 0;
}