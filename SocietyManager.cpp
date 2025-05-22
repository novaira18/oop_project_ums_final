#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Society {
    string societyID;
    string societyName;
    string presidentName;
};
struct SocietyMember {
    string memberID;
    string name;
    string societyID;
    string role;
};
class SocietyManager {
private:
    vector<Society> societies;
    vector<SocietyMember> societyMembers;
    int findSocietyIndex(const string& societyID) {
        for (size_t i = 0; i < societies.size(); ++i) {
            if (societies[i].societyID == societyID)
                return i;
        }
        return -1;
    }
    int findMemberIndex(const string& memberID) {
        for (size_t i = 0; i < societyMembers.size(); ++i) {
            if (societyMembers[i].memberID == memberID)
                return i;
        }
        return -1;
    }
public:
    void addSociety() {
        Society s;
        cout << "Enter Society ID: ";
        cin >> s.societyID;
        cin.ignore();
        cout << "Enter Society Name: ";
        getline(cin, s.societyName);
        cout << "Enter President Name: ";
        getline(cin, s.presidentName);
        societies.push_back(s);
        cout << "Society added successfully.\n";
    }
    void viewSocieties() {
        cout << "\n--- Societies ---\n";
        for (const auto& s : societies) {
            cout << "Society ID: " << s.societyID << "\n";
            cout << "Society Name: " << s.societyName << "\n";
            cout << "President Name: " << s.presidentName << "\n";
            cout << "------------------------\n";
        }
    }
    void editSociety(const string& societyID) {
        int index = findSocietyIndex(societyID);
        if (index == -1) {
            cout << "Society not found.\n";
            return;
        }
        cout << "Editing Society: " << societies[index].societyName << "\n";
        cout << "Enter new Society Name: ";
        cin.ignore();
        getline(cin, societies[index].societyName);
        cout << "Enter new President Name: ";
        getline(cin, societies[index].presidentName);
        cout << "Society updated successfully.\n";
    }
    void deleteSociety(const string& societyID) {
        int index = findSocietyIndex(societyID);
        if (index == -1) {
            cout << "Society not found.\n";
            return;
        }
        societies.erase(societies.begin() + index);
        cout << "Society deleted successfully.\n";
        // Remove all members of this society
        societyMembers.erase(remove_if(societyMembers.begin(), societyMembers.end(),
            [societyID](const SocietyMember& m) {
                return m.societyID == societyID;
            }), societyMembers.end());
    }
    void addSocietyMember() {
        SocietyMember m;
        cout << "Enter Member ID: ";
        cin >> m.memberID;
        cin.ignore();
        cout << "Enter Member Name: ";
        getline(cin, m.name);
        cout << "Enter Society ID: ";
        getline(cin, m.societyID);
        cout << "Enter Role (e.g. Vice President, Member): ";
        getline(cin, m.role);
        societyMembers.push_back(m);
        cout << "Society member added successfully.\n";
    }
    void viewSocietyMembers() {
        cout << "\n--- Society Members ---\n";
        for (const auto& m : societyMembers) {
            cout << "Member ID: " << m.memberID << "\n";
            cout << "Name: " << m.name << "\n";
            cout << "Society ID: " << m.societyID << "\n";
            cout << "Role: " << m.role << "\n";
            cout << "------------------------\n";
        }
    }
    void editSocietyMember(const string& memberID) {
        int index = findMemberIndex(memberID);
        if (index == -1) {
            cout << "Member not found.\n";
            return;
        }
        cout << "Editing Member: " << societyMembers[index].name << "\n";
        cout << "Enter new Name: ";
        cin.ignore();
        getline(cin, societyMembers[index].name);
        cout << "Enter new Role: ";
        getline(cin, societyMembers[index].role);
        cout << "Society member updated successfully.\n";
    }
    void deleteSocietyMember(const string& memberID) {
        int index = findMemberIndex(memberID);
        if (index == -1) {
            cout << "Member not found.\n";
            return;
        }
        societyMembers.erase(societyMembers.begin() + index);
        cout << "Society member deleted successfully.\n";
    }
};
// Sample menu-driven main function

