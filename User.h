#include "Person.h"
using namespace std;

class User : public Person {
protected:
    string userID;
    string role;
    string contactNumber;
public:
    string getUsername() const;
    string getRole() const;
    string getName() const;
    void setPassword(const string& newPassword);
    void setContact(const string& contact);
    virtual bool verifyPassword(const string& enteredPassword);
    virtual void showPanel() = 0;
    virtual ~User() {}
};
