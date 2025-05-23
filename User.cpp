#include "User.h"
#include <iostream>
#include <fstream>
#include <conio.h> // for _getch()
#include <vector>

using namespace std;

// Constructor
User::User(string name, string email, string cnic, string registrationId,
           string username, string password, string userID,
           string role, string contactNumber)
    : Person(name, email, cnic, registrationId, username, password),
      userID(userID), role(role), contactNumber(contactNumber) { }

// Default constructor for placeholder object
User::User() : Person("", "", "", "", "", ""), userID(""), role(""), contactNumber("") { }

// Getter functions
string User::getUsername() const {
    return username;
}

string User::getRole() const {
    return role;
}

string User::getName() const {
    return name;
}

// Setters
void User::setPassword(const string& newPassword) {
    password = newPassword;
}

void User::setContact(const string& contact) {
    contactNumber = contact;
}

// Password verification
bool User::verifyPassword(const string& enteredPassword) {
    return password == enteredPassword;
}

// Password input with masking
string User::inputMaskedPassword() {
    string pwd;
    char ch;
    while ((ch = _getch()) != '\r') { // until Enter
        if (ch == '\b') {
            if (!pwd.empty()) {
                cout << "\b \b";
                pwd.pop_back();
            }
        } else {
            pwd += ch;
            cout << '*';
        }
    }
    cout << endl;
    return pwd;
}

// Load users from file
void User::loadUsersFromFile(const string& filename) {
    ifstream file(filename);
    string name, email, cnic, regId, username, password, userID, role, contact;

    while (getline(file, name) &&
           getline(file, email) &&
           getline(file, cnic) &&
           getline(file, regId) &&
           getline(file, username) &&
           getline(file, password) &&
           getline(file, userID) &&
           getline(file, role) &&
           getline(file, contact)) {
        User u(name, email, cnic, regId, username, password, userID, role, contact);
        users.push_back(u);
    }

    file.close();
}

// Menu display
void User::displayMenu() {
    cout << "\n===== LOGIN MENU =====\n";
    cout << "[1] Login as Admin\n";
    cout << "[2] Login as Faculty\n";
    cout << "[3] Login as Student\n";
    cout << "[4] Login as University General\n";
    cout << "[5] Login as Society Member\n";
    cout << "[0] Exit\n";
    cout << "Select option: ";
}

// Get role by choice
string User::getRoleFromChoice(int choice) {
    switch (choice) {
        case 1: return "Admin";
        case 2: return "Faculty";
        case 3: return "Student";
        case 4: return "UniversityGeneral";
        case 5: return "SocietyMember";
        default: return "";
    }
}

// Login process
User* User::processLogin(const string& role) {
    string enteredUsername, enteredPassword;

    cout << "Enter Username: ";
    cin >> enteredUsername;
    cout << "Enter Password: ";
    enteredPassword = inputMaskedPassword();

    for (auto& user : users) {
        if (user.getUsername() == enteredUsername && user.getRole() == role) {
            if (user.verifyPassword(enteredPassword)) {
                cout << "Login successful! Welcome, " << user.getName() << " [" << user.getRole() << "]\n";
                return &user;
            }
        }
    }

    cout << "Invalid credentials or role mismatch.\n";
    return nullptr;
}

// Login menu handler
void User::loginMenu() {
    loadUsersFromFile("users.txt"); // Load data once per session

    int choice;
    do {
        displayMenu();
        cin >> choice;

        if (choice == 0) break;

        string role = getRoleFromChoice(choice);
        if (role.empty()) {
            cout << "Invalid option. Try again.\n";
            continue;
        }

        processLogin(role);

    } while (choice != 0);

    cout << "Exiting login system...\n";
}

// Destructor
User::~User() {
    // Optional cleanup
}
