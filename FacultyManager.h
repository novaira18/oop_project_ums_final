#include <vector>
#include <string>
#include "FilePaths.h"

using namespace std;

struct Faculty {
    string facultyID;
    string facultyName;
    string dean;
};

class FacultyManager {
private:
    vector<Faculty> faculties;
    void loadFromFile();
    void saveToFile();

public:
    FacultyManager();  // constructor loads data from file
    void addFaculty();
    void viewFaculties();
    void editFaculty(const string& facultyID);
    void deleteFaculty(const string& facultyID);
    Faculty* findFaculty(const string& facultyID);
};
