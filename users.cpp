#include "users.h"
int main() 
{
    int user_type;
    cout << "Select user type:" << endl;
    cout << "1. Normal User" << endl;
    cout << "2. Admin" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> user_type;
    cin.ignore();

    string input_username;
    string input_password;
    cout << "Enter username: ";
    getline(cin, input_username);
    cout << "Enter password: ";
    getline(cin, input_password);

    if (user_type == 1) {
        User normal_user(input_username, input_password);
        if (normal_user.login(input_username, input_password)) {
            run_user_menu(normal_user);
        }
    } else if (user_type == 2) {
        Admin admin_user(input_username, input_password);
        if (admin_user.login(input_username, input_password)) {
            run_admin_menu(admin_user);
        }
    } else {
        cout << "Invalid user type selected." << endl;
    }
    return 0;
}