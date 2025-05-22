#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Credential {
    string userID;
    string username;
    string password;
    string role;
};
class UserCredentialManager {
private:
    vector<Credential> credentials;
    int findCredentialIndexByUserID(const string& userID) {
        for (size_t i = 0; i < credentials.size(); ++i) {
            if (credentials[i].userID == userID)
                return (int)i;
        }
        return -1;
    }
    int findCredentialIndexByUsername(const string& username) {
        for (size_t i = 0; i < credentials.size(); ++i) {
            if (credentials[i].username == username)
                return (int)i;
        }
        return -1;
    }
    void addCredential() {
        Credential c;
        cout << "Enter User ID: ";
        cin >> c.userID;
        cin.ignore();
        cout << "Enter Username: ";
        getline(cin, c.username);
        cout << "Enter Password: ";
        getline(cin, c.password);
        cout << "Enter Role: ";
        getline(cin, c.role);
        credentials.push_back(c);
        cout << "Credential added successfully.\n";
    }
    void changePassword(const string& userID) {
        int idx = findCredentialIndexByUserID(userID);
        if (idx == -1) {
            cout << "UserID not found.\n";
            return;
        }
        cout << "Enter new password for user " << credentials[idx].username << ": ";
        string newPass;
        cin.ignore();
        getline(cin, newPass);
        credentials[idx].password = newPass;
        cout << "Password changed successfully.\n";
    }
    void resetPassword(const string& userID) {
        int idx = findCredentialIndexByUserID(userID);
        if (idx == -1) {
            cout << "UserID not found.\n";
            return;
        }
        credentials[idx].password = "default123";  // Example default password
        cout << "Password reset to default123 for user " << credentials[idx].username << ".\n";
    }
    bool verifyLogin(const string& username, const string& password) {
        int idx = findCredentialIndexByUsername(username);
        if (idx == -1) return false;
        return credentials[idx].password == password;
    }
    void viewCredentials() {
        if (credentials.empty()) {
            cout << "No credentials stored.\n";
            return;
        }
        cout << "\n--- Stored Credentials ---\n";
        for (const auto& c : credentials) {
            cout << "UserID: " << c.userID << ", Username: " << c.username
                 << ", Role: " << c.role << "\n";
        }
    }
public:
    void menu() {
        int choice;
        while (true) {
            cout << "\n--- User Credential Management ---\n";
            cout << "1. Add Credential\n";
            cout << "2. Change Password\n";
            cout << "3. Reset Password\n";
            cout << "4. Verify Login\n";
            cout << "5. View All Credentials\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    addCredential();
                    break;
                case 2: {
                    cout << "Enter User ID to change password: ";
                    string userID; cin >> userID;
                    changePassword(userID);
                    break;
                }
                case 3: {
                    cout << "Enter User ID to reset password: ";
                    string userID; cin >> userID;
                    resetPassword(userID);
                    break;
                }
                case 4: {
                    cin.ignore();
                    cout << "Enter Username: ";
                    string username; getline(cin, username);
                    cout << "Enter Password: ";
                    string password; getline(cin, password);
                    if (verifyLogin(username, password))
                        cout << "Login successful!\n";
                    else
                        cout << "Invalid username or password.\n";
                    break;
                }
                case 5:
                    viewCredentials();
                    break;
                case 6:
                    cout << "Exiting User Credential Management...\n";
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};
