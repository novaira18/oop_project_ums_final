#include <vector>
#include <string>
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

public:
    void addUGMember();
    void viewUGMembers();
    void editUGMember(const string& ugID);
    void deleteUGMember(const string& ugID);
};
