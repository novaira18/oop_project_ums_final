#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct UGMember {
    string ugID;
    string name;
    string department;
    string designation;
};
class UGManager {
private:
    vector<UGMember> ugMembers;
    int findUGMemberIndex(const string& ugID) {
        for (size_t i = 0; i < ugMembers.size(); ++i) {
            if (ugMembers[i].ugID == ugID)
                return i;
        }
        return -1;
    }
    void addUGMember() {
        UGMember m;
        cout << "Enter UG Member ID: ";
        cin >> m.ugID;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, m.name);
        cout << "Enter Department: ";
        getline(cin, m.department);
        cout << "Enter Designation: ";
        getline(cin, m.designation);
        ugMembers.push_back(m);
        cout << "UG Member added successfully.\n";
    }
    void viewUGMembers() {
        if (ugMembers.empty()) {
            cout << "No UG Members available.\n";
            return;
        }
        cout << "\n--- UG Members List ---\n";
        for (const auto& m : ugMembers) {
            cout << "UG ID: " << m.ugID << "\n";
            cout << "Name: " << m.name << "\n";
            cout << "Department: " << m.department << "\n";
            cout << "Designation: " << m.designation << "\n";
            cout << "--------------------------\n";
        }
    }
    void editUGMember() {
        string ugID;
        cout << "Enter UG Member ID to edit: ";
        cin >> ugID;
        int index = findUGMemberIndex(ugID);
        if (index == -1) {
            cout << "UG Member not found.\n";
            return;
        }
        cout << "Editing UG Member: " << ugMembers[index].name << "\n";
        cin.ignore();
        cout << "Enter new Name: ";
        getline(cin, ugMembers[index].name);
        cout << "Enter new Department: ";
        getline(cin, ugMembers[index].department);
        cout << "Enter new Designation: ";
        getline(cin, ugMembers[index].designation);
        cout << "UG Member updated successfully.\n";
    }
    void deleteUGMember() {
        string ugID;
        cout << "Enter UG Member ID to delete: ";
        cin >> ugID;
        int index = findUGMemberIndex(ugID);
        if (index == -1) {
            cout << "UG Member not found.\n";
            return;
        }
        ugMembers.erase(ugMembers.begin() + index);
        cout << "UG Member deleted successfully.\n";
    }
public:
    void menu() {
        int choice;
        while (true) {
            cout << "\n--- UG Member Management ---\n";
            cout << "1. Add UG Member\n";
            cout << "2. View UG Members\n";
            cout << "3. Edit UG Member\n";
            cout << "4. Delete UG Member\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    addUGMember();
                    break;
                case 2:
                    viewUGMembers();
                    break;
                case 3:
                    editUGMember();
                    break;
                case 4:
                    deleteUGMember();
                    break;
                case 5:
                    cout << "Exiting UG Member Management...\n";
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};
