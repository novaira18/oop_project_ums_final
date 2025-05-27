#include "Student.h"
#include <iostream>
#include<vector>
using namespace std;

void StudentAcademicViewer::viewProfile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "❌ Failed to open file: " << filename << endl;
        return;
    }

    vector<map<string, string>> students;
    map<string, string> student;
    string line;

    int lineCount = 0;

    while (getline(file, line)) {
        if (line.empty()) continue;  // skip any blank lines

        size_t delimiter = line.find(':');
        if (delimiter != string::npos) {
            string key = line.substr(0, delimiter);
            string value = line.substr(delimiter + 1);
            student[key] = value;
            lineCount++;
        }

        // After every 6 lines (i.e., full student record), save and reset
        if (lineCount == 6) {
            students.push_back(student);
            student.clear();
            lineCount = 0;
        }
    }

    file.close();

    if (students.empty()) {
        cout << "⚠️ No student records found." << endl;
        return;
    }

    // Display student records
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "\n📘 Student #" << i + 1 << ":\n";
        for (const auto& [key, value] : students[i]) {
            cout << key << ": " << value << endl;
        }
    }
}

StudentAcademicViewer::viewRegisteredCourses() {
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "❌ Failed to open file: " << filepath << endl;
        return;
    }

    string line;
    vector<string> courses;

    while (getline(file, line)) {
        size_t delimiter = line.find(':');
        if (delimiter != string::npos) {
            string courseName = line.substr(delimiter + 1);
            if (!courseName.empty()) {
                courses.push_back(courseName);
            }
        }
    }

    file.close();

    // Display all courses
    cout << "\n📚 Enrolled Courses:\n";
    for (size_t i = 0; i < courses.size(); ++i) {
        cout << "- " << courses[i] << endl;
    }

    if (courses.empty()) {
        cout << "⚠️ No courses found in file." << endl;
    }
}

StudentAcademicViewer::viewTimetable(const string& filename) {
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "❌ Failed to open file: " << filepath << endl;
        return;
    }

    string line;
    bool isHeaderSkipped = false;
    map<string, vector<string>> timetable;

    while (getline(file, line)) {
        if (line.empty()) continue;

        // Skip the first line (time slot header)
        if (!isHeaderSkipped) {
            isHeaderSkipped = true;
            continue;
        }

        istringstream iss(line);
        string day;
        iss >> day;

        string session;
        vector<string> sessions;

        while (iss >> session) {
            sessions.push_back(session);
        }

        timetable[day] = sessions;
    }

    file.close();

    // Display the timetable
    cout << "\n🗓️ Student Timetable:\n";
    cout << left << setw(12) << "Day"
        << setw(15) << "8:00-9:00"
        << setw(15) << "9:30-10:30"
        << setw(15) << "10:30-12:00" << endl;
    cout << string(57, '-') << endl;

    for (const auto& [day, sessions] : timetable) {
        cout << left << setw(12) << day;
        for (const auto& s : sessions) {
            cout << setw(15) << s;
        }
        cout << endl;
    }
}

StudentAcademicViewer::viewFeeInvoice(const string& studentID) {
    string filename = studentID + ".txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "❌ Could not find file for student ID: " << studentID << endl;
        return;
    }

    string course;
    int courseCount = 0;

    cout << "\n📄 Fee Invoice for Student ID: " << studentID << endl;
    cout << "--------------------------------------" << endl;
    cout << "Registered Courses:\n";

    while (getline(file, course)) {
        if (!course.empty()) {
            courseCount++;
            cout << "- " << course << endl;
        }
    }

    int totalFee = courseCount * 10000;
    cout << "--------------------------------------" << endl;
    cout << "Total Courses: " << courseCount << endl;
    cout << "Fee per Course: Rs. 10,000" << endl;
    cout << "📌 Total Fee: Rs. " << totalFee << endl;

    file.close();
}
