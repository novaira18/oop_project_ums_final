#include "FacultyManager.h"
#include <iostream>
using namespace std;
void FacultyManager::addFaculty() {
    Faculty f;
    cout << "Enter Faculty ID: ";
    getline(cin, f.facultyID);
    cout << "Enter Faculty Name: ";
    getline(cin, f.facultyName);
    cout << "Enter Dean Name: ";
    getline(cin, f.dean);
    faculties.push_back(f);
    cout << "Faculty added successfully.\n";
}
void FacultyManager::viewFaculties() {
    if (faculties.empty()) {
        cout << "No faculties available.\n";
        return;
    }
    cout << "List of Faculties:\n";
    for (const auto& f : faculties) {
        cout << "Faculty ID: " << f.facultyID
             << ", Name: " << f.facultyName
             << ", Dean: " << f.dean << '\n';
    }
}
void FacultyManager::editFaculty(const string& facultyID) {
    for (auto& f : faculties) {
        if (f.facultyID == facultyID) {
            cout << "Editing Faculty: " << f.facultyName << endl;
            cout << "Enter new Faculty Name (leave empty to keep current): ";
            string input;
            getline(cin, input);
            if (!input.empty()) f.facultyName = input;
            cout << "Enter new Dean Name (leave empty to keep current): ";
            getline(cin, input);
            if (!input.empty()) f.dean = input;
            cout << "Faculty updated successfully.\n";
            return;
        }
    }
    cout << "Faculty with ID '" << facultyID << "' not found.\n";
}
void FacultyManager::deleteFaculty(const string& facultyID) {
    for (auto it = faculties.begin(); it != faculties.end(); ++it) {
        if (it->facultyID == facultyID) {
            faculties.erase(it);
            cout << "Faculty deleted successfully.\n";
            return;
        }
    }
    cout << "Faculty with ID '" << facultyID << "' not found.\n";
}
