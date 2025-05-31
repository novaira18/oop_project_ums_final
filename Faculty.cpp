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

void FacultyActionManager::assignGrades() {
    string filename;
    cout << "Enter filename containing enrolled students: ";
    cin >> filename;

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    map<string, pair<string, string>> studentData; // rollno -> (name, grade)
    string line;

    while (getline(inFile, line)) {
        size_t firstDelim = line.find(':');
        if (firstDelim == string::npos) {
            cerr << "Warning: Invalid line format (missing ':') - " << line << endl;
            continue;
        }

        string rollno = line.substr(0, firstDelim);
        string remaining = line.substr(firstDelim + 1);

        size_t secondDelim = remaining.find(':');
        string name = (secondDelim != string::npos) ? remaining.substr(0, secondDelim) : remaining;
        string grade = (secondDelim != string::npos) ? remaining.substr(secondDelim + 1) : "";

        // Trim whitespace
        auto trim = [](string& s) {
            s.erase(0, s.find_first_not_of(" \t"));
            s.erase(s.find_last_not_of(" \t") + 1);
            };
        trim(rollno);
        trim(name);
        trim(grade);

        studentData[rollno] = { name, grade };
    }
    inFile.close();

    // Get grades from faculty
    for (auto& [rollno, info] : studentData) {
        while (true) {
            cout << "Enter grade for " << info.first << " (" << rollno << "): ";
            getline(cin >> ws, info.second);

            // Optional: Validate grade format (e.g., A, B, C, D, F)
            if (info.second.empty()) {
                cout << "Grade cannot be empty. Try again." << endl;
            }
            else {
                break;
            }
        }
    }

    // Write to a temporary file first
    string tempFile = filename + ".tmp";
    ofstream outFile(tempFile);
    if (!outFile) {
        cerr << "Error: Cannot write to temporary file " << tempFile << endl;
        return;
    }

    for (const auto& [rollno, info] : studentData) {
        outFile << rollno << ":" << info.first << ":" << info.second << "\n";
    }
    outFile.close();

    // Replace original file
    if (rename(tempFile.c_str(), filename.c_str()) != 0) {
        cerr << "Error: Failed to update file " << filename << endl;
        remove(tempFile.c_str()); // Clean up temp file
        return;
    }

    cout << "Grades assigned successfully.\n";
}

void FacultyActionManager::markAttendance() {
    string inputFilename, outputFilename;

    cout << "Enter filename of enrolled students: ";
    cin >> inputFilename;
    cout << "Enter filename to save attendance (e.g., attendance.txt): ";
    cin >> outputFilename;

    // Check if output file exists
    ifstream test(outputFilename);
    if (test.good()) {
        cout << "Warning: " << outputFilename << " already exists. Overwrite? (Y/N): ";
        char choice;
        cin >> choice;
        if (tolower(choice) != 'y') {
            cout << "Cancelled." << endl;
            return;
        }
    }
    test.close();

    ifstream file(inputFilename);
    if (!file) {
        cerr << "Error: Could not open file " << inputFilename << endl;
        return;
    }

    map<string, string> enrolledStudents;
    string line;

    while (getline(file, line)) {
        size_t delimiterPos = line.find(':');
        if (delimiterPos == string::npos) {
            cerr << "Warning: Invalid line (missing ':') - " << line << endl;
            continue;
        }

        string studentID = line.substr(0, delimiterPos);
        string studentName = line.substr(delimiterPos + 1);

        // Trim whitespace
        auto trim = [](string& s) {
            s.erase(0, s.find_first_not_of(" \t"));
            s.erase(s.find_last_not_of(" \t") + 1);
            };
        trim(studentID);
        trim(studentName);

        if (enrolledStudents.count(studentID)) {
            cerr << "Warning: Duplicate ID " << studentID << " - overwriting." << endl;
        }
        enrolledStudents[studentID] = studentName;
    }
    file.close();

    if (enrolledStudents.empty()) {
        cerr << "Error: No students found in " << inputFilename << endl;
        return;
    }

    map<string, string> attendanceMap;

    cout << "\n--- Mark Attendance ---\n";
    for (const auto& student : enrolledStudents) {
        string status;
        while (true) {
            cout << student.first << " | " << student.second << " (P/A/S=Skip): ";
            cin >> status;

            if (status.empty()) continue;
            status = toupper(status[0]); // Capitalize first character

            if (status == "P" || status == "A") break;
            if (status == "S") {
                status = "N/A"; // Mark as skipped
                break;
            }
            cout << "Invalid input. Enter P (Present), A (Absent), or S (Skip).\n";
        }
        attendanceMap[student.first] = status;
    }

    // Print summary before saving
    cout << "\n--- Attendance Summary ---\n";
    for (const auto& student : enrolledStudents) {
        cout << student.first << " | " << student.second << " : " << attendanceMap[student.first] << endl;
    }

    cout << "Save to file? (Y/N): ";
    char confirm;
    cin >> confirm;
    if (tolower(confirm) != 'y') {
        cout << "Cancelled." << endl;
        return;
    }

    // Write to a temporary file first
    string tempFile = outputFilename + ".tmp";
    ofstream outFile(tempFile);
    if (!outFile) {
        cerr << "Error: Could not write to file " << tempFile << endl;
        return;
    }

    // Add timestamp
    time_t now = time(0);
    outFile << "# Attendance recorded on: " << ctime(&now);

    for (const auto& student : enrolledStudents) {
        outFile << student.first << ":" << student.second << ":" << attendanceMap[student.first] << "\n";
    }
    outFile.close();

    // Replace original file
    if (rename(tempFile.c_str(), outputFilename.c_str()) != 0) {
        cerr << "Error: Failed to update " << outputFilename << endl;
        remove(tempFile.c_str());
        return;
    }

    cout << "\nAttendance recorded successfully in " << outputFilename << "\n";
}
