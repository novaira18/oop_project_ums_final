#include "Society.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

//Member management functions
  //View
void MemberManagement ::  ViewMembers(){
ifstream inFile("members.txt");
    
    if (!inFile) {
        cerr << "Error: Could not open members.txt\n";
        return;
    }

    memberNames.clear(); //clearing the vector
    memberRoles.clear(); //clearing the map

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, role;

        if (getline(ss, name, ',') && getline(ss, role)) {
            memberNames.push_back(name);
            memberRoles[name] = role;
        }
    }

    inFile.close();

    cout << "Members of " << societyName << ":\n";
    for (const string& name : memberNames) {
        cout << "- " << name << " (" << memberRoles[name] << ")\n";
    }
}

  //Add
void MemberManagement::addMembers() {
    string name, role;
    cout << "Enter member name: ";
    getline(cin, name);
    cout << "Enter member role: ";
    getline(cin, role);

    ofstream outFile("members.txt", ios::app);

    if (!outFile) {
        cerr << "Error: Could not open members.txt for writing.\n";
        return;
    }

    outFile << name << "," << role << "\n";
    outFile.close();

    cout << "Member '" << name << "' with role '" << role << "' added successfully.\n";
}


  //Logout
  void MemberManagement::Logout() {
    cout << "\nLogging out from " << societyName << " management panel...\n";
    cout << "Thank you for managing the society. Goodbye!\n";
}

void EventManager::AddEvents() {
    Event newEvent;

    cout << "Enter event title: ";
    getline(cin, newEvent.title);
    cout << "Enter event date (YYYY-MM-DD): ";
    getline(cin, newEvent.date);
    cout << "Enter event location: ";
    getline(cin, newEvent.location);
    cout << "Enter event description: ";
    getline(cin, newEvent.description);

    newEvent.isApproved = false;  // New events need approval

    // Save to pendingApprovalEvents vector and file
    pendingApprovalEvents.push_back(newEvent);

    // Append event to pending approval file
    ofstream outFile("pending_events.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Could not open pending_events.txt for writing.\n";
        return;
    }

    outFile << newEvent.title << "|" 
            << newEvent.date << "|" 
            << newEvent.location << "|" 
            << newEvent.description << "|" 
            << newEvent.isApproved << "\n";

    outFile.close();

    cout << "Event added and pending approval.\n";
}

void EventManager::loadPendingEvents() {
    pendingApprovalEvents.clear();

    ifstream inFile("pending_events.txt");
    if (!inFile) {
        // No pending events file, treat as empty
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Event e;
        string approvedStr;

        getline(ss, e.title, '|');
        getline(ss, e.date, '|');
        getline(ss, e.location, '|');
        getline(ss, e.description, '|');
        getline(ss, approvedStr);

        // Pending events should be unapproved, but parse anyway
        e.isApproved = (approvedStr == "1" || approvedStr == "true");

        pendingApprovalEvents.push_back(e);
    }

    inFile.close();
}

void EventManager::RequestApprovalForEvents() {
    loadPendingEvents();  // Load pending events fresh from file

    if (pendingApprovalEvents.empty()) {
        cout << "No pending events for approval.\n";
        return;
    }
     if (pendingApprovalEvents.empty()) {
        cout << "No pending events for approval.\n";
        return;
    }

    cout << "Pending Events:\n";

    for (size_t i = 0; i < pendingApprovalEvents.size(); ++i) {
        const Event& e = pendingApprovalEvents[i];
        cout << i + 1 << ". " << e.title << " on " << e.date << " at " << e.location << "\n";
        cout << "   Description: " << e.description << "\n";
    }

    cout << "Enter the number of the event to approve (0 to cancel): ";
    int choice;
    cin >> choice;
    cin.ignore();  // clear newline from buffer

    if (choice <= 0 || choice > (int)pendingApprovalEvents.size()) {
        cout << "Approval cancelled or invalid choice.\n";
        return;
    }

    // Approve the event
    pendingApprovalEvents[choice - 1].isApproved = true;
    eventList.push_back(pendingApprovalEvents[choice - 1]);

    // Remove approved event from pending list
    pendingApprovalEvents.erase(pendingApprovalEvents.begin() + (choice - 1));

    cout << "Event approved successfully.\n";

    // Rewrite pending_events.txt without the approved event
    ofstream pendingFile("pending_events.txt");
    if (!pendingFile) {
        cerr << "Error: Could not open pending_events.txt to update.\n";
        return;
    }
    for (const auto& e : pendingApprovalEvents) {
        pendingFile << e.title << "|" << e.date << "|" << e.location << "|" << e.description << "|" << e.isApproved << "\n";
    }
    pendingFile.close();

    // Append approved event to events.txt
    ofstream approvedFile("events.txt", ios::app);
    if (!approvedFile) {
        cerr << "Error: Could not open events.txt for writing.\n";
        return;
    }
    const Event& approvedEvent = eventList.back();
    approvedFile << approvedEvent.title << "|" << approvedEvent.date << "|" << approvedEvent.location << "|" << approvedEvent.description << "|" << approvedEvent.isApproved << "\n";
    approvedFile.close();
}

void EventManager::ViewPreviousEvents() {
    eventList.clear();

    ifstream inFile("events.txt");
    if (!inFile) {
        cout << "No approved events found.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Event e;
        string approvedStr;

        getline(ss, e.title, '|');
        getline(ss, e.date, '|');
        getline(ss, e.location, '|');
        getline(ss, e.description, '|');
        getline(ss, approvedStr);

        e.isApproved = (approvedStr == "1" || approvedStr == "true");

        eventList.push_back(e);
    }

    inFile.close();

    if (eventList.empty()) {
        cout << "No approved events to display.\n";
        return;
    }

    cout << "Approved Events:\n";
    for (const auto& e : eventList) {
        cout << "- " << e.title << " on " << e.date << " at " << e.location << "\n";
        cout << "  Description: " << e.description << "\n\n";
    }
}

void EventManager::ViewPreviousEvents() {
    eventList.clear();

    ifstream inFile("events.txt");
    if (!inFile) {
        cout << "No approved events found.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Event e;
        string approvedStr;

        getline(ss, e.title, '|');
        getline(ss, e.date, '|');
        getline(ss, e.location, '|');
        getline(ss, e.description, '|');
        getline(ss, approvedStr);

        e.isApproved = (approvedStr == "1" || approvedStr == "true");

        eventList.push_back(e);
    }

    inFile.close();

    if (eventList.empty()) {
        cout << "No approved events to display.\n";
        return;
    }

    cout << "Approved Events:\n";
    for (const auto& e : eventList) {
        cout << "- " << e.title << " on " << e.date << " at " << e.location << "\n";
        cout << "  Description: " << e.description << "\n\n";
    }
}
