#include <vector>
#include <string>
#include "FilePaths.h"

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
    string facultyID;
    string membersFileName;

    void loadFromFile();
    void saveToFile();

public:
    FacultyMemberManager(const string& facultyID);
    void addFacultyMember();
    void viewFacultyMembers();
    void editFacultyMember(const string& memberID);
    void deleteFacultyMember(const string& memberID);
    FacultyMember* findFacultyMember(const string& memberID);
};
