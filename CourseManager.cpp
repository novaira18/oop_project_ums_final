#include "CourseManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
const string COURSE_DATA_FILE = "data/courses.txt";
CourseManager::CourseManager() {
    loadCoursesFromFile();
}
void CourseManager::loadCoursesFromFile() {
    courses.clear();
    ifstream file(COURSE_DATA_FILE);
    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        Course c;
        getline(ss, c.courseID, ',');
        getline(ss, c.courseName, ',');
        getline(ss, c.deptID, ',');
        getline(ss, c.assignedFacultyID, ',');
        courses.push_back(c);
    }
    file.close();
}
void CourseManager::saveCoursesToFile() {
    ofstream file(COURSE_DATA_FILE);
    for (const auto& c : courses) {
        file << c.courseID << ","
             << c.courseName << ","
             << c.deptID << ","
             << c.assignedFacultyID << "\n";
    }
    file.close();
}
void CourseManager::addCourseToDepartment(const string& deptID) {
    Course c;
    cout << "Enter Course ID: ";
    getline(cin, c.courseID);
    cout << "Enter Course Name: ";
    getline(cin, c.courseName);
    c.deptID = deptID;
    c.assignedFacultyID = ""; // initially unassigned
    courses.push_back(c);
    saveCoursesToFile();
    cout << "Course added successfully.\n";
}
void CourseManager::assignCourseToFaculty(const string& courseID, const string& facultyID) {
    auto it = find_if(courses.begin(), courses.end(),
                      [&](const Course& c) { return c.courseID == courseID; });
    if (it != courses.end()) {
        it->assignedFacultyID = facultyID;
        saveCoursesToFile();
        cout << "Faculty assigned to course.\n";
    } else {
        cout << "Course ID not found.\n";
    }
}
void CourseManager::enrollStudentInCourse(const string& studentID, const string& courseID) {
    // For now, we only simulate it (you may link this with a StudentManager system later)
    cout << "Enrolling student " << studentID << " in course " << courseID << " (simulated).\n";
    // Can expand: add to student's enrolledCourses or create separate enrollment records
}
void CourseManager::viewCourseList(const string& deptID) {
    cout << "Course List:\n";
    for (const auto& c : courses) {
        if (!deptID.empty() && c.deptID != deptID) continue;
        cout << "Course ID: " << c.courseID << ", Name: " << c.courseName
             << ", Department: " << c.deptID
             << ", Faculty Assigned: " << (c.assignedFacultyID.empty() ? "None" : c.assignedFacultyID)
             << "\n";
    }
}
