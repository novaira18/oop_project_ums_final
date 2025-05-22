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
public:
    void addDepartment(const string& facultyID);
    void viewDepartments(const string& facultyID = "");
    void editDepartment(const string& deptID);
    void deleteDepartment(const string& deptID);
};

