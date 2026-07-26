#pragma once
#include <iostream>
#include <string>
using namespace std;
const int MAX_HISTORY_SIZE = 100;
class User {
private:
    string username;
    string password;
    public:
    string calculation_history[MAX_HISTORY_SIZE];
    int history_count;
    User(string user_name, string user_password) {
        username = user_name;
        password = user_password;
        history_count = 0;
        for (int index = 0; index < MAX_HISTORY_SIZE; index++) {
            calculation_history[index] = "";
        }
    }
    bool login(string user_name, string user_password) {
        if (user_name == username && user_password == password) {
            cout << "Login successful! Welcome, " << username << "." << endl;
            return true;
        }
        cout << "Invalid username or password." << endl;
        return false;
    }

    void select_shape() {
        cout << "Please select a shape to calculate." << endl;
    }

    void view_history() {
        if (history_count == 0) {
            cout << "No calculations in history." << endl;
        } else {
            cout << "Calculation History (" << history_count << " entries):" << endl;
            for (int index = 0; index < history_count; index++) {
                cout << "- " << calculation_history[index] << endl;
            }
        }
    }

    void add_to_history(string calculation) {
        if (history_count < MAX_HISTORY_SIZE) {
            calculation_history[history_count] = calculation;
            history_count = history_count + 1;
        } else {
            cout << "History is full. Cannot add more calculations." << endl;
        }
    }

    string get_username() {
        return username;
    }
};

class Admin : public User {
public:
    Admin(string user_name, string user_password) : User(user_name, user_password) {}
  
    // Later
    void modify_shapes() 
    {
        cout << "Admin " << get_username() << " is updating the list of shapes." << endl;
    }

    void clear_data() {
        for (int index = 0; index < MAX_HISTORY_SIZE; index++) {
            calculation_history[index] = "";
        }
        history_count = 0;
        cout << "All calculation data cleared by admin " << get_username() << "." << endl;
    }

    void select_shape() {
        cout << "Admin is selecting shapes with advanced options." << endl;
    }
};

void run_user_menu(User& user) {
    cout << "Welcome to User Panel!" << endl;
    cout << "1. Add calculation to history" << endl;
    cout << "2. View calculation history" << endl;
    cout << "3. Select shape" << endl;
    cout << "4. Exit" << endl;

    int choice;
    string calculation;
    do {
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            cout << "Enter calculation to add: ";
            getline(cin, calculation);
            user.add_to_history(calculation);
        } else if (choice == 2) {
            user.view_history();
        } else if (choice == 3) {
            user.select_shape();
        } else if (choice == 4) {
            cout << "Logging out. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

void run_admin_menu(Admin& admin) {
    cout << "Welcome to Admin Panel!" << endl;
    cout << "1. Add calculation to history" << endl;
    cout << "2. View calculation history" << endl;
    cout << "3. Select shape" << endl;
    cout << "4. Modify shapes" << endl;
    cout << "5. Clear all data" << endl;
    cout << "6. Exit" << endl;

    int choice;
    string calculation;
    do {
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            cout << "Enter calculation to add: ";
            getline(cin, calculation);
            admin.add_to_history(calculation);
        } else if (choice == 2) {
            admin.view_history();
        } else if (choice == 3) {
            admin.select_shape();
        } else if (choice == 4) {
            admin.modify_shapes();
        } else if (choice == 5) {
            admin.clear_data();
        } else if (choice == 6) {
            cout << "Logging out. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}

