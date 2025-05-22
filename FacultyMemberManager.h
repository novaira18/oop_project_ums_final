#include <vector>
#include <string>
using namespace std;

struct FacultyMember {
    string memberID;
    string name;
    string deptID;
    string position;
};
class FacultyMemberManager {
private:
    vector<FacultyMember> facultyMembers;
public:
    void addFacultyMember();
    void viewFacultyMembers();
    void editFacultyMember(const string& memberID);
    void deleteFacultyMember(const string& memberID);
};
