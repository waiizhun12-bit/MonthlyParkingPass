#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
using namespace std;

void header (string sub);
void split (void);
int option (string array[], int size);
void invalid (void);

void login (int &step); // Login
void regis (int &step); // Register

void studentAuth_menu();
void admin_menu();
void list_pending_applications();

#endif