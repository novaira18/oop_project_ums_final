#include <string>
#include <vector>

// Abstract Base Class
class Faculty {
public:
    virtual void viewPersonalInfo() = 0;
    virtual void viewAssignedCourses() = 0;
    virtual void viewEnrolledStudents() = 0;
    virtual void markAttendance() = 0;
    virtual void assignGrades() = 0;

    virtual ~Faculty() {}
};

// Subclass for Viewing Faculty Information
class FacultyInfoViewer : public Faculty {
public:
    void viewPersonalInfo() override;
    void viewAssignedCourses() override;
    void viewEnrolledStudents() override;
};

// Subclass for Faculty Actions (Attendance and Grades)
class FacultyActionManager : public Faculty {
public:
    void markAttendance() override;
    void assignGrades() override;
};


