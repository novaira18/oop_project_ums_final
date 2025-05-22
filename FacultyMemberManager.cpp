#include "FacultyMemberManager.h"
#include <iostream>
using namespace std;
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
    facultyMembers.push_back(fm);
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
void FacultyMemberManager::editFacultyMember(const string& memberID) {
    for (auto& fm : facultyMembers) {
        if (fm.memberID == memberID) {
            cout << "Editing Faculty Member: " << fm.name << '\n';
            cout << "Enter new Name (leave empty to keep current): ";
            string input;
            getline(cin, input);
            if (!input.empty()) fm.name = input;
            cout << "Enter new Department ID (leave empty to keep current): ";
            getline(cin, input);
            if (!input.empty()) fm.deptID = input;
            cout << "Enter new Position (leave empty to keep current): ";
            getline(cin, input);
            if (!input.empty()) fm.position = input;
            cout << "Faculty member updated successfully.\n";
            return;
        }
    }
    cout << "Faculty member with ID '" << memberID << "' not found.\n";
}
void FacultyMemberManager::deleteFacultyMember(const string& memberID) {
    for (auto it = facultyMembers.begin(); it != facultyMembers.end(); ++it) {
        if (it->memberID == memberID) {
            facultyMembers.erase(it);
            cout << "Faculty member deleted successfully.\n";
            return;
        }
    }
    cout << "Faculty member with ID '" << memberID << "' not found.\n";
}
