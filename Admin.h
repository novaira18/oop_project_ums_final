#include "User.h"

class Admin : public User {
public:
    void showPanel() override;
    void manageFaculties();
    void manageDepartments();
    void manageStudents();
    void manageFacultyMembers();
    void manageCourses();
    void manageCredentials();
    void manageUGF();
    void manageSocieties();
};
