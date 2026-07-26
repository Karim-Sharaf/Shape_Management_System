#include <iostream>
using namespace std;

#include "UI.h"
#include "UI.cpp"

int main() {
	UI ui;
    int choice = ui.MainMenu();

    if (choice == 1) {
	//        auto [user, pass, type] = ui.GetShapeInput();

	//    tuple<string, string, int> input = ui.GetShapeInput();

	array<string, 3> input = ui.GetShapeInput();
    string user = input[0];
    string pass = input[1];
    string type = input[2];
		ui.PrintResult("Welcome, " + user + "! You're logged in as a(n) " + type + ".");
    } else if (choice == 2) {
        ui.PrintResult("History Viewer not yet implemented.");
    } else {
        ui.PrintResult("Goodbye!");
    }

    return 0;
}
