#include "Admin.h"
#include <iostream>
using namespace std;

// Constructor definition
Admin::Admin(string name, string email, string cnic, string registrationId,
             string username, string password, string userID,
             string role, string contactNumber)
    : User(name, email, cnic, registrationId, username, password, userID, role, contactNumber) { }

// Show Panel
void Admin::showPanel() {
    cout << "Admin Panel\n";
    cout << "1. Manage Faculties\n";
    cout << "2. Manage Departments\n";
    cout << "3. Manage Students\n";
    cout << "4. Manage Faculty Members\n";
    cout << "5. Manage Courses\n";
    cout << "6. Manage Credentials\n";
    cout << "7. Manage University General\n";
    cout << "8. Manage Societies\n";
}

// Stub implementations
void Admin::manageFaculties() {
    cout << "Managing faculties...\n";
}

void Admin::manageDepartments() {
    cout << "Managing departments...\n";
}

void Admin::manageStudents() {
    cout << "Managing students...\n";
}

void Admin::manageFacultyMembers() {
    cout << "Managing faculty members...\n";
}

void Admin::manageCourses() {
    cout << "Managing courses...\n";
}

void Admin::manageCredentials() {
    cout << "Managing credentials...\n";
}

void Admin::manageUG() {
    cout << "Managing UGF...\n";
}

void Admin::manageSocieties() {
    cout << "Managing societies...\n";
}
