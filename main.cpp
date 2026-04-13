#include <iostream>
#include <string>
#include "system.h"
using namespace std;

void menu (int &step);  // Main menu

int main () {
    int step = 0;

    while (step >= 0) {
        if (step == 0) menu(step);
        if (step == 1) login(step);
        if (step == 2) regis(step);
        if (step == 3) studentMenu(step);
        if (step == -1) admin_menu(step);
    }
    return 0;
}

void menu (int &step) {
	header("Main Menu");
	
	string arr[] = {"Login","Register","Exit"};

    switch (option(arr, 3)) {
        case 1: step = 1; break;
        case 2: step = 2; break;
        case 3: step = 99; break;
        default: invalid(); break;
    }
}