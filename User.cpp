#include "User.h"

// Constructor
User::User(string name, string email, string cnic, string registrationId,
           string username, string password, string userID,
           string role, string contactNumber)
    : Person(name, email, cnic, registrationId, username, password),
      userID(userID), role(role), contactNumber(contactNumber) { }

string User::getUsername() const {
    return username;
}

string User::getRole() const {
    return role;
}

string User::getName() const {
    return name;
}

void User::setPassword(const string& newPassword) {
    password = newPassword;
}

void User::setContact(const string& contact) {
    contactNumber = contact;
}

bool User::verifyPassword(const string& enteredPassword) {
    return password == enteredPassword;
}

string User::maskedInput() {
    string input;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b' && !input.empty()) {
            cout << "\b \b";
            input.pop_back();
        } else if (ch != '\b') {
            cout << '*';
            input += ch;
        }
    }
    cout << endl;
    return input;
}

// Menu logic and login simulation
User* User::showLoginMenu() {
    int choice;
    cout << "\n=== University Login Menu ===\n";
    cout << "[1] Login as Admin\n";
    cout << "[2] Login as Faculty\n";
    cout << "[3] Login as Student\n";
    cout << "[4] Login as University General\n";
    cout << "[5] Login as Society Member\n";
    cout << "[0] Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 0) return nullptr;

    string uname, pword;
    cout << "Username: ";
    getline(cin, uname);
    cout << "Password: ";
    pword = maskedInput();

    // Dummy login with hardcoded users (extend with file handling later)
    if (uname == "admin" && pword == "admin123" && choice == 1) {
        class AdminUser : public User {
        public:
            AdminUser() : User("Admin", "admin@uni.com", "12345", "R001", "admin", "admin123", "U001", "Admin", "03111234567") {}
            void showPanel() override {
                cout << "\n-- Admin Panel --\n1. Manage Users\n2. View Logs\n";
            }
        };
        return new AdminUser();
    }

    if (uname == "faculty" && pword == "fac123" && choice == 2) {
        class FacultyUser : public User {
        public:
            FacultyUser() : User("Faculty", "fac@uni.com", "67890", "R002", "faculty", "fac123", "U002", "Faculty", "03222345678") {}
            void showPanel() override {
                cout << "\n-- Faculty Panel --\n1. View Timetable\n2. Upload Marks\n";
            }
        };
        return new FacultyUser();
    }

    if (uname == "student" && pword == "stud123" && choice == 3) {
        class StudentUser : public User {
        public:
            StudentUser() : User("Student", "stu@uni.com", "13579", "R003", "student", "stud123", "U003", "Student", "03333456789") {}
            void showPanel() override {
                cout << "\n-- Student Panel --\n1. View Grades\n2. Enroll Courses\n";
            }
        };
        return new StudentUser();
    }

    if (uname == "general" && pword == "gen123" && choice == 4) {
        class GeneralUser : public User {
        public:
            GeneralUser() : User("General Staff", "gen@uni.com", "11223", "R004", "general", "gen123", "U004", "General", "03444567890") {}
            void showPanel() override {
                cout << "\n-- General Staff Panel --\n1. View Schedule\n2. Notify Students\n";
            }
        };
        return new GeneralUser();
    }

    if (uname == "society" && pword == "soc123" && choice == 5) {
        class SocietyMember : public User {
        public:
            SocietyMember() : User("Society Member", "soc@uni.com", "99887", "R005", "society", "soc123", "U005", "Society", "03555678901") {}
            void showPanel() override {
                cout << "\n-- Society Panel --\n1. Organize Event\n2. Check Members\n";
            }
        };
        return new SocietyMember();
    }

    cout << "\nInvalid credentials or selection.\n";
    return nullptr;
}

User::~User() {
    // Optional cleanup
}
