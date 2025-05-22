#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    Student* findStudent(const string& studentID) {
        for (auto& s : students) {
            if (s.studentID == studentID)
                return &s;
        }
        return nullptr;
    }
public:
    void addStudent() {
        Student s;
        cout << "Enter Student ID: ";
        getline(cin, s.studentID);
        if (findStudent(s.studentID)) {
            cout << "Student with ID '" << s.studentID << "' already exists.\n";
            return;
        }
        cout << "Enter Name: ";
        getline(cin, s.name);
        cout << "Enter Department ID: ";
        getline(cin, s.deptID);
        cout << "Enter Faculty ID: ";
        getline(cin, s.facultyID);
        int courseCount;
        cout << "Enter number of courses to enroll: ";
        cin >> courseCount;
        cin.ignore();
        for (int i = 0; i < courseCount; ++i) {
            string course;
            cout << "Enter course " << (i + 1) << ": ";
            getline(cin, course);
            s.enrolledCourses.push_back(course);
        }
        students.push_back(s);
        cout << "Student added successfully.\n";
    }
    void viewStudents(const string& deptID = "", const string& facultyID = "") {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }
        for (const auto& s : students) {
            if ((!deptID.empty() && s.deptID != deptID) ||
                (!facultyID.empty() && s.facultyID != facultyID)) {
                continue;
            }
            cout << "ID: " << s.studentID << ", Name: " << s.name
                 << ", Dept: " << s.deptID << ", Faculty: " << s.facultyID << "\n";
            cout << "Enrolled Courses: ";
            for (const auto& c : s.enrolledCourses)
                cout << c << " ";
            cout << "\n---\n";
        }
    }
    void editStudent(const string& studentID) {
        Student* s = findStudent(studentID);
        if (!s) {
            cout << "Student with ID '" << studentID << "' not found.\n";
            return;
        }
        cout << "Editing Student: " << s->name << endl;
        string input;
        cout << "Enter new Name (leave empty to keep current): ";
        getline(cin, input);
        if (!input.empty()) s->name = input;
        cout << "Enter new Department ID (leave empty to keep current): ";
        getline(cin, input);
        if (!input.empty()) s->deptID = input;
        cout << "Enter new Faculty ID (leave empty to keep current): ";
        getline(cin, input);
        if (!input.empty()) s->facultyID = input;
        cout << "Do you want to update enrolled courses? (y/n): ";
        getline(cin, input);
        if (input == "y" || input == "Y") {
            s->enrolledCourses.clear();
            int courseCount;
            cout << "Enter number of courses: ";
            cin >> courseCount;
            cin.ignore();
            for (int i = 0; i < courseCount; ++i) {
                string course;
                cout << "Enter course " << (i + 1) << ": ";
                getline(cin, course);
                s->enrolledCourses.push_back(course);
            }
        }
        cout << "Student updated successfully.\n";
    }
    void deleteStudent(const string& studentID) {
        auto it = remove_if(students.begin(), students.end(),
                            [&](const Student& s) { return s.studentID == studentID; });
        if (it == students.end()) {
            cout << "Student with ID '" << studentID << "' not found.\n";
            return;
        }
        students.erase(it, students.end());
        cout << "Student deleted successfully.\n";
    }
};
