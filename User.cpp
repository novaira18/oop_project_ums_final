#include "User.h"

// Constructor definition
User::User(string name, string email, string cnic, string registrationId,
           string username, string password, string userID,
           string role, string contactNumber)
    : Person(name, email, cnic, registrationId, username, password),
      userID(userID), role(role), contactNumber(contactNumber) { }

// Getter functions
string User::getUsername() const {
    return username;
}

string User::getRole() const {
    return role;
}

string User::getName() const {
    return name;
}

// Setters
void User::setPassword(const string& newPassword) {
    password = newPassword;
}

void User::setContact(const string& contact) {
    contactNumber = contact;
}

// Virtual function for password verification
bool User::verifyPassword(const string& enteredPassword) {
    return password == enteredPassword;
}

// Destructor
User::~User() {
    // Optional cleanup
}
