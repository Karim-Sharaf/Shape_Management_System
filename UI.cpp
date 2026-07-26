#include <iostream>
using namespace std;

#include <limits>
#include <array>
#include <string>

#include "UI.h"

void UI::ClearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

bool UI::ValidateInput(int input, int min, int max) {
	return input >= min && input <= max;
}

int UI::MainMenu() {
	int choice;
	cout << "===== Main Menu =====\n";
	cout << "1. Calculate Shape\n";
	cout << "2. View History\n";
	cout << "3. Exit\n";
	cout << "Enter your choice: ";
	cin >> choice;
	
	while (!ValidateInput(choice, 1, 3)) {
		cout << "Invalid choice. Try again: ";
		cin >> choice;
	}
	
	return choice;
}

//tuple<string, string, string> UI::GetShapeInput() {
//	cout << "===== User Input =====\n";
//	cout << "Username: ";
//	cin >> userName;
//	cout << "Password: ";
//	cin >> password;
//	cout << "User Type (admin/user): ";
//	cin >> userType;
//	return make_tuple(userName, password, userType);
//}

array<std::string, 3> UI::GetShapeInput() {
	//	string user, pass, type;

    cout << "Enter username: ";
    cin >> userName;

    cout << "Enter password: ";
    cin >> password;

    cout << "Enter type: ";
    cin >> userType;

    return {userName, password, userType};
}

void UI::PrintResult(string msg) {
	cout << ">>> " << msg << endl;
}
