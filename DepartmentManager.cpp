#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Department {
    string deptID;
    string deptName;
    string facultyID;
    string head;
};
class DepartmentManager {
private:
    vector<Department> departments;
    int findDepartmentIndex(const string& deptID) {
        for (size_t i = 0; i < departments.size(); ++i) {
            if (departments[i].deptID == deptID)
                return i;
        }
        return -1;
    }
public:
    void addDepartment(const string& facultyID) {
        Department dept;
        cout << "Enter Department ID: ";
        cin >> dept.deptID;
        cout << "Enter Department Name: ";
        cin.ignore(); // to clear newline
        getline(cin, dept.deptName);
        dept.facultyID = facultyID;
        cout << "Enter Head of Department: ";
        getline(cin, dept.head);
        departments.push_back(dept);
        cout << "Department added successfully.\n";
    }
    void viewDepartments(const string& facultyID = "") {
        cout << "\n--- Department List ---\n";
        for (const auto& dept : departments) {
            if (facultyID.empty() || dept.facultyID == facultyID) {
                cout << "Dept ID: " << dept.deptID << "\n";
                cout << "Dept Name: " << dept.deptName << "\n";
                cout << "Faculty ID: " << dept.facultyID << "\n";
                cout << "Head: " << dept.head << "\n";
                cout << "-----------------------\n";
            }
        }
    }
    void editDepartment(const string& deptID) {
        int index = findDepartmentIndex(deptID);
        if (index == -1) {
            cout << "Department not found.\n";
            return;
        }
        cout << "Editing Department: " << departments[index].deptName << "\n";
        cout << "Enter new Department Name: ";
        cin.ignore();
        getline(cin, departments[index].deptName);
        cout << "Enter new Head of Department: ";
        getline(cin, departments[index].head);
        cout << "Department updated successfully.\n";
    }
    void deleteDepartment(const string& deptID) {
        int index = findDepartmentIndex(deptID);
        if (index == -1) {
            cout << "Department not found.\n";
            return;
        }
        departments.erase(departments.begin() + index);
        cout << "Department deleted successfully.\n";
    }
};
// Sample main function to demonstrate usage
int main() {
    DepartmentManager dm;
    string facultyID, deptID;
    int choice;
    while (true) {
        cout << "\n1. Add Department\n2. View Departments\n3. Edit Department\n4. Delete Department\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Faculty ID for Department: ";
                cin >> facultyID;
                dm.addDepartment(facultyID);
                break;
            case 2:
                cout << "Enter Faculty ID to filter (or press Enter to view all): ";
                cin.ignore();
                getline(cin, facultyID);
                dm.viewDepartments(facultyID);
                break;
            case 3:
                cout << "Enter Department ID to edit: ";
                cin >> deptID;
                dm.editDepartment(deptID);
                break;
            case 4:
                cout << "Enter Department ID to delete: ";
                cin >> deptID;
                dm.deleteDepartment(deptID);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
