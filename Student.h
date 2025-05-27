#include <string>
#include <vector>

// Abstract Base Class
class Student {
public:
    virtual void viewProfile() = 0;
    virtual void viewRegisteredCourses() = 0;
    virtual void viewAttendance() = 0;
    virtual void viewGrades() = 0;
    virtual void viewTimetable() = 0;
    virtual void viewFeeInvoice() = 0;
    virtual void giveFeedback() = 0;

    virtual ~Student() {}
};

// Subclass for Academic Info and Schedule
class StudentAcademicViewer : public Student {
public:
    void viewProfile() override;
    void viewRegisteredCourses() override;
    void viewAttendance() override;
    void viewGrades() override;
    void viewTimetable() override;
};

// Subclass for Finance and Feedback
class StudentSupportManager : public Student {
public:
    void viewFeeInvoice() override;
    void giveFeedback() override;
};
