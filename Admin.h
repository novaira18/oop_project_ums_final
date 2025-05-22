#include "User.h"

class Admin : public User {
public:
    // Constructor
    Admin(string name, string email, string cnic, string registrationId,
          string username, string password, string userID,
          string role, string contactNumber);

    void showPanel() override;

    void manageFaculties();
    void manageDepartments();
    void manageStudents();
    void manageFacultyMembers();
    void manageCourses();
    void manageCredentials();
    void manageUG();
    void manageSocieties();
};
