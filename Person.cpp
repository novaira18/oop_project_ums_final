#include "Person.h"

// Constructor definition
Person::Person(string name, string email, string cnic,
               string registrationId, string username, string password)
    : name(name), email(email), cnic(cnic),
      registrationId(registrationId), username(username), password(password) { }

// Destructor definition
Person::~Person() {
    // Nothing specific yet, but important for proper cleanup in derived classes
}
