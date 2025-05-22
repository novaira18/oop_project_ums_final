#include "FacultyMemberManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

FacultyMemberManager::FacultyMemberManager(const string& facultyID) : facultyID(facultyID) {
    membersFileName = facultyMembersFile(facultyID);
    loadFromFile();
}

void FacultyMemberManager::loadFromFile() {
    facultyMembers.clear();
    ifstream fin(membersFileName);
    if (!fin) return;

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        FacultyMember fm;
        getline(ss, fm.memberID, ',');
        getline(ss, fm.name, ',');
        getline(ss, fm.deptID, ',');
        getline(ss, fm.position, ',');

        facultyMembers.push_back(fm);
    }
    fin.close();
}

void FacultyMemberManager::saveToFile() {
    ofstream fout(membersFileName, ios::trunc);
    for (const auto& fm : facultyMembers) {
        fout << fm.memberID << "," << fm.name << "," << fm.deptID << "," << fm.position << "\n";
    }
    fout.close();
}

void FacultyMemberManager::addFacultyMember() {
    FacultyMember fm;
    cout << "Enter Member ID: ";
    getline(cin, fm.memberID);
    cout << "Enter Name: ";
    getline(cin, fm.name);
    cout << "Enter Department ID: ";
    getline(cin, fm.deptID);
    cout << "Enter Position: ";
    getline(cin, fm.position);

    if (findFacultyMember(fm.memberID) != nullptr) {
        cout << "Faculty member with this ID already exists.\n";
        return;
    }

    facultyMembers.push_back(fm);
    saveToFile();
    cout << "Faculty member added successfully.\n";
}

void FacultyMemberManager::viewFacultyMembers() {
    if (facultyMembers.empty()) {
        cout << "No faculty members found.\n";
        return;
    }
    cout << "List of Faculty Members:\n";
    for (const auto& fm : facultyMembers) {
        cout << "Member ID: " << fm.memberID 
             << ", Name: " << fm.name 
             << ", Department ID: " << fm.deptID 
             << ", Position: " << fm.position << '\n';
    }
}

FacultyMember* FacultyMemberManager::findFacultyMember(const string& memberID) {
    for (auto& fm : facultyMembers) {
        if (fm.memberID == memberID)
            return &fm;
    }
    return nullptr;
}

void FacultyMemberManager::editFacultyMember(const string& memberID) {
    FacultyMember* fm = findFacultyMember(memberID);
    if (!fm) {
        cout << "Faculty member with ID '" << memberID << "' not found.\n";
        return;
    }
    cout << "Editing Faculty Member: " << fm->name << endl;
    cout << "Enter new Name (leave empty to keep current): ";
    string input;
    getline(cin, input);
    if (!input.empty()) fm->name = input;

    cout << "Enter new Department ID (leave empty to keep current): ";
    getline(cin, input);
    if (!input.empty()) fm->deptID = input;

    cout << "Enter new Position (leave empty to keep current): ";
    getline(cin, input);
    if (!input.empty()) fm->position = input;

    saveToFile();
    cout << "Faculty member updated successfully.\n";
}

void FacultyMemberManager::deleteFacultyMember(const string& memberID) {
    auto it = facultyMembers.begin();
    for (; it != facultyMembers.end(); ++it) {
        if (it->memberID == memberID) break;
    }
    if (it == facultyMembers.end()) {
        cout << "Faculty member with ID '" << memberID << "' not found.\n";
        return;
    }
    facultyMembers.erase(it);
    saveToFile();
    cout << "Faculty member deleted successfully.\n";
}
