#include <vector>
#include <string>
using namespace std;

struct Student {
    string studentID;
    string name;
    string deptID;
    string facultyID;
    vector<string> enrolledCourses;
};

class StudentManager {
private:
    vector<Student> students;
public:
    void addStudent();
    void viewStudents(const string& deptID = "", const string& facultyID = "");
    void editStudent(const string& studentID);
    void deleteStudent(const string& studentID);
};
