#include <string>
#include <vector>
#include <map>
using namespace std;

class SocietyMenu {
public:
    virtual ~SocietyMenu() {}

    // Interface methods
    virtual void addMembers() = 0;
    virtual void ViewMembers() = 0;
    virtual void AddEvents() = 0;
    virtual void loadPendingEvents() = 0;
    virtual void RequestApprovalForEvents() = 0;
    virtual void ViewPreviousEvents() = 0;
    virtual void Logout() = 0;
};

// ========== Member Management ==========
class MemberManagement : public SocietyMenu {
private:
    vector<string> memberNames;
    map<string, string> memberRoles; // e.g., { "Ali", "President" }
    string societyName;

public:
    // Overridden functions
    void addMembers() override;
    void ViewMembers() override;
    void Logout() override;
};

// ========== Event Manager ==========
class EventManager : public SocietyMenu {
private:
    struct Event {
        string title;
        string date;
        string location;
        string description;
        bool isApproved;
    };

    vector<Event> eventList;
    vector<Event> pendingApprovalEvents;
    string societyName;

public:
    void AddEvents() override;
    void loadPendingEvents() override;
    void RequestApprovalForEvents() override;
    void ViewPreviousEvents() override;
    void Logout() override;
};



