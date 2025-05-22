#include <string>
#include <vector>
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
    int findCredentialIndexByUserID(const string& userID);
    int findCredentialIndexByUsername(const string& username);
    void addCredential();
    void changePassword(const string& userID);
    void resetPassword(const string& userID);
    bool verifyLogin(const string& username, const string& password);
    void viewCredentials();
public:
    void menu(); 
};

