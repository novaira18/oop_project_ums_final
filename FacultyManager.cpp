#include "FacultyManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

FacultyManager::FacultyManager() {
    loadFromFile();
}

void FacultyManager::loadFromFile() {
    faculties.clear();
    ifstream fin(FACULTY_DATA_FILE);
    if (!fin) {
        // File may not exist yet, no problem
        return;
    }
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, dean;
        // Read comma-separated values
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, dean, ',');
        faculties.push_back({id, name, dean});
    }
    fin.close();
}

void FacultyManager::saveToFile() {
    ofstream fout(FACULTY_DATA_FILE, ios::trunc);
    for (const auto& f : faculties) {
        fout << f.facultyID << "," << f.facultyName << "," << f.dean << "\n";
    }
    fout.close();
}

void FacultyManager::addFaculty() {
    Faculty f;
    cout << "Enter Faculty ID: ";
    getline(cin, f.facultyID);
    cout << "Enter Faculty Name: ";
    getline(cin, f.facultyName);
    cout << "Enter Dean Name: ";
    getline(cin, f.dean);

    // Check duplicate
    if (findFaculty(f.facultyID) != nullptr) {
        cout << "Faculty with this ID already exists.\n";
        return;
    }

    faculties.push_back(f);
    saveToFile();

    // Create empty faculty members file for this faculty
    ofstream fout(facultyMembersFile(f.facultyID));
    fout.close();

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

Faculty* FacultyManager::findFaculty(const string& facultyID) {
    for (auto& f : faculties) {
        if (f.facultyID == facultyID)
            return &f;
    }
    return nullptr;
}

void FacultyManager::editFaculty(const string& facultyID) {
    Faculty* f = findFaculty(facultyID);
    if (!f) {
        cout << "Faculty with ID '" << facultyID << "' not found.\n";
        return;
    }
    cout << "Editing Faculty: " << f->facultyName << endl;
    cout << "Enter new Faculty Name (leave empty to keep current): ";
    string input;
    getline(cin, input);
    if (!input.empty()) f->facultyName = input;

    cout << "Enter new Dean Name (leave empty to keep current): ";
    getline(cin, input);
    if (!input.empty()) f->dean = input;

    saveToFile();
    cout << "Faculty updated successfully.\n";
}

void FacultyManager::deleteFaculty(const string& facultyID) {
    auto it = faculties.begin();
    for (; it != faculties.end(); ++it) {
        if (it->facultyID == facultyID) break;
    }
    if (it == faculties.end()) {
        cout << "Faculty with ID '" << facultyID << "' not found.\n";
        return;
    }
    faculties.erase(it);
    saveToFile();

    // Delete corresponding faculty members file
    string fileName = facultyMembersFile(facultyID);
    if (remove(fileName.c_str()) == 0) {
        cout << "Faculty members file deleted.\n";
    } else {
        cout << "Failed to delete faculty members file or file does not exist.\n";
    }

    cout << "Faculty deleted successfully.\n";
}
