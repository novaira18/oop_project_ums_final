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
public:
    void changePassword(const string& userID);
    void resetPassword(const string& userID);
    bool verifyLogin(const string& username, const string& password);
};
