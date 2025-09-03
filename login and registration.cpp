#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {//function
    string username, password;

    cout << "\n>>> Registration <<<\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ofstream file("user.txt");
    file << username << endl << password;
    file.close();

    cout << "User Registered Successfully!!\n";
}

void loginUser() {//function
    string username, password, storeduser, storedpass;

    cout << "\n>>> Login <<<\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file("user.txt");
    if (!file) {
        cout << "Error!! User not found!!\n";
        return; // stop here if file doesn't exist
    }

    getline(file, storeduser);
    getline(file, storedpass);
    file.close();

    if (username == storeduser && password == storedpass) {
        cout << "Login Successful!!! Welcome " << username << "!\n";
    } else {
        cout << "Login Failed!! Invalid Credentials...\n";
    }
}

int main() {
    int choice;

    cout << "-------------------------------------------------------------" << endl;
    cout << ">>>>>>>>>>>>>>>> LOGIN & REGISTRATION SYSTEM <<<<<<<<<<<<<<<<<" << endl;
    cout << "-------------------------------------------------------------" << endl;

    while (true) {
        cout << "\n1. Registration \n2. Login \n3. Exit \nChoose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting Program...\n";
                return 0;
            default:
                cout << "Invalid Choice!\n";
        }
    }
}

