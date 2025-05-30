#include <iostream>
#include <conio.h> // For getch()
#include "Admin.h" // Include your class headers
#include "Faculty.h"
#include "Student.h"
#include "UniversityGeneral.h"
#include "SocietyMember.h"

using namespace std;

int main() {
    // Display welcome message
    cout << "Welcome to the University Management System!" << endl;

    // Login menu
    int choice;
    do {
        cout << "Login Menu:" << endl;
        cout << "[1] Login as Admin" << endl;
        cout << "[2] Login as Faculty" << endl;
        cout << "[3] Login as Student" << endl;
        cout << "[4] Login as University General" << endl;
        cout << "[5] Login as Society Member" << endl;
        cout << "[0] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Handle Admin login
                break;
            case 2:
                // Handle Faculty login
                break;
            case 3:
                // Handle Student login
                break;
            case 4:
                // Handle University General login
                break;
            case 5:
                // Handle Society Member login
                break;
            case 0:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
