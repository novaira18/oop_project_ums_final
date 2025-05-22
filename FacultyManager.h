#include <vector>
#include <string>
using namespace std;

struct Faculty {
    string facultyID;
    string facultyName;
    string dean;
};

class FacultyManager {
private:
    vector<Faculty> faculties;

public:
    void addFaculty();
    void viewFaculties();
    void editFaculty(const string& facultyID);
    void deleteFaculty(const string& facultyID);
};

