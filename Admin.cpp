#include <iostream>
#include "admin.h"
#include "FacultyManager.h"
#include "DepartmentManager.h"
#include "StudentManager.h"
#include "FacultyMemberManager.h"
#include "CourseManager.h"
#include "CredentialManager.h"
#include "UGManager.h"
#include "SocietyManager.h"

using namespace std;

void Admin::showMenu() {
    int choice;
    do {
        cout << "\n👑 ADMIN PANEL\n";
        cout << "[1] Manage Faculties\n";
        cout << "[2] Manage Departments\n";
        cout << "[3] Manage Students\n";
        cout << "[4] Manage Faculty Members\n";
        cout << "[5] Courses Management\n";
        cout << "[6] Manage User Credentials\n";
        cout << "[7] University General Management\n";
        cout << "[8] Societies Management\n";
        cout << "[9] Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: FacultyManager().menu(); break;
            case 2: DepartmentManager().menu(); break;
            case 3: StudentManager().menu(); break;
            case 4: FacultyMemberManager().menu(); break;
            case 5: CourseManager().menu(); break;
            case 6: CredentialManager().menu(); break;
            case 7: UGManager().menu(); break;
            case 8: SocietyManager().menu(); break;
            case 9: cout << "Logging out...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 9);
}
