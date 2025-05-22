#include <string>
using namespace std;

class Person {
protected:
    string name;
    string email;
    string cnic;
    string registrationId;
    string username;
    string password;
public:
    virtual void showMenu() = 0;
    virtual void viewProfile() = 0;
    virtual ~Person() {}
};
