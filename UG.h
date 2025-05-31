#include <string>
using namespace std;

// Abstract Base Class
class UGM {
public:
    // Events
    virtual void Add() = 0;
    virtual void View() = 0;
    virtual void Edit() = 0;
    virtual void Delete() = 0;

    // Notice Board
    virtual void Post(const string& filename) = 0;
    virtual void ViewNotices() = 0;

    // Library
    virtual void AddBook() = 0;
    virtual void ViewBooks() = 0;
    virtual void IssueBook() = 0;
    virtual void ReturnBook() = 0;

    // Sports Complex
    virtual void BookSlot() = 0;
    virtual void ViewEquipment() = 0;



    // Hostel Info
    virtual void AllotRoom() = 0;
    virtual void ViewRoomData() = 0;

    virtual ~UGM() {}
};

// ---------- Derived Sub-Classes ----------

// Notice Board
class NoticeBoard : public UGM {
public:
    void Post(const string& filename) override;
    void ViewNotices() override;
};

// Library
class Library : public UGM {
public:
    void AddBook() override;
    void ViewBooks() override;
    void IssueBook() override;
    void ReturnBook() override;
};

// Sports Complex
class SportsComplex : public UGM {
public:
    void BookSlot() override;
    void ViewEquipment() override;
};

// Hostel Info
class HostelInfo : public UGM {
public:
    void AllotRoom() override;
    void ViewRoomData() override;
};



