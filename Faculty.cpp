#include "Faculty.h"
#include <iostream>
#include<vector>
using namespace std;

void FacultyInfoViewer::viewPersonalInfo(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    map<string, string> personalInfo;
    string line;

    while (getline(file, line)) {
        size_t delimiterPos = line.find(':'); 
        if (delimiterPos != string::npos) {
            string key = line.substr(0, delimiterPos); // Used to store the string till : which is the key
            string value = line.substr(delimiterPos + 1); // Used to store the value 

            // Trim leading/trailing whitespace (optional)
            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);

            personalInfo[key] = value;
        }
    }

    file.close();

    // Display the parsed map
    cout << "Personal Info (Key: Value)\n";
    for (const auto& pair : personalInfo) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void FacultyInfoViewer::viewEnrolledStudents(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    map<string, string> enrolledStudents;
    string line;

    // Read and parse each line into the map
    while (getline(file, line)) {
        size_t delimiterPos = line.find(':');
        if (delimiterPos != string::npos) {
            string studentID = line.substr(0, delimiterPos);
            string studentName = line.substr(delimiterPos + 1);

            // Trim whitespace
            studentID.erase(0, studentID.find_first_not_of(" \t"));
            studentID.erase(studentID.find_last_not_of(" \t") + 1);
            studentName.erase(0, studentName.find_first_not_of(" \t"));
            studentName.erase(studentName.find_last_not_of(" \t") + 1);

            enrolledStudents[studentID] = studentName;
        }
    }

    file.close();

    // Display enrolled students
    cout << "\n--- Enrolled Students ---\n";
    for (const auto& student : enrolledStudents) {
        cout << "ID: " << student.first << " | Name: " << student.second << endl;
    }
}

void FacultyInfoViewer::viewAssignedCourses(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    map<string, string> assignedCourses;
    string line;

    // Read and parse each line
    while (getline(file, line)) {
        size_t delimiterPos = line.find(':');
        if (delimiterPos != string::npos) {
            string courseID = line.substr(0, delimiterPos);
            string courseName = line.substr(delimiterPos + 1);

            // Trim whitespace
            courseID.erase(0, courseID.find_first_not_of(" \t"));
            courseID.erase(courseID.find_last_not_of(" \t") + 1);
            courseName.erase(0, courseName.find_first_not_of(" \t"));
            courseName.erase(courseName.find_last_not_of(" \t") + 1);

            assignedCourses[courseID] = courseName;
        }
    }

    file.close();

    // Display the assigned courses
    cout << "\n--- Assigned Courses ---\n";
    for (const auto& course : assignedCourses) {
        cout << "Course ID: " << course.first << " | Course Name: " << course.second << endl;
    }
}

