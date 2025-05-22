#include <vector>
#include <string>
using namespace std;

struct Course {
    string courseID;
    string courseName;
    string deptID;
    string assignedFacultyID;
};
class CourseManager {
private:
    vector<Course> courses;
public:
    void addCourseToDepartment(const string& deptID);
    void assignCourseToFaculty(const string& courseID, const string& facultyID);
    void enrollStudentInCourse(const string& studentID, const string& courseID);
    void viewCourseList(const string& deptID = "");
};

