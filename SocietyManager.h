#include <vector>
#include <string>
using namespace std;

struct Society {
    string societyID;
    string societyName;
    string presidentName;
};
struct SocietyMember {
    string memberID;
    string name;
    string societyID;
    string role;
};
class SocietyManager {
private:
    vector<Society> societies;
    vector<SocietyMember> societyMembers;
public:
    void addSociety();
    void viewSocieties();
    void editSociety(const string& societyID);
    void deleteSociety(const string& societyID);
    void addSocietyMember();
    void viewSocietyMembers();
    void editSocietyMember(const string& memberID);
    void deleteSocietyMember(const string& memberID);
};
