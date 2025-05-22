#include <string>
using namespace std;

const string STUDENT_DATA_FILE = "data/students.txt";
const string FACULTY_DATA_FILE = "data/faculty.txt";        
const string DEPARTMENT_DATA_FILE = "data/departments.txt";
const string COURSE_DATA_FILE = "data/courses.txt";
const string CREDENTIALS_FILE = "data/credentials.txt";
const string UG_MEMBERS_FILE = "data/ug_members.txt";
const string SOCIETIES_FILE = "data/societies.txt";

// Helper function to get filename for a specific faculty's members file
inline string facultyMembersFile(const string& facultyID) {
    return "data/faculty_" + facultyID + "_members.txt";
}

