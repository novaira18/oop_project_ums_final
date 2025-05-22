#include <string>
#include <vector>
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
    int findUGMemberIndex(const string& ugID);
    void addUGMember();
    void viewUGMembers();
    void editUGMember();
    void deleteUGMember();
public:
    void menu();  // Add this declaration
};

