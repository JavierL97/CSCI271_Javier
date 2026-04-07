// lab12_Javier.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student {
protected:
    string name;
    string id;
public:
    Student(string n, string i) : name(n), id(i) {}
    virtual ~Student() = default;

    virtual void displayInfo() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};
class CollegeStudent : public Student {
    string major;
    double gpa;
public:
    CollegeStudent(string n, string i, string m, double g)
        : Student(n, i), major(m), gpa(g) {}

    void displayInfo() const override {
        cout << "Name: " << name << ", ID: " << id
             << ", Major: " << major << ", GPA: " << gpa << endl;
    }
};
class GraduateStudent : public Student {
    string researchTopic;
public:
    GraduateStudent(string n, string i, string topic)
        : Student(n, i), researchTopic(topic) {}

    void displayInfo() const override {
        cout << "Name: " << name << ", ID: " << id
             << ", Topic: " << researchTopic << endl;
    }
};

class Project {
    string projectName;
    GraduateStudent leader;
    CollegeStudent member;
public:
    Project(string pName, const GraduateStudent& l, const CollegeStudent& m)
        : projectName(pName), leader(l), member(m) {}

    void displayProjectInfo() const {
        cout << "Project: " << projectName << endl;
        cout << "Leader: ";
        leader.displayInfo();
        cout << "Member: ";
        member.displayInfo();
    }
};

int main() {
    GraduateStudent gradLeader("Scott", "M011", "Artificial Intelligence");
    CollegeStudent collMember("Tom", "CS001", "Computer Science", 3.1);

    cout << "--- Individual Student Info ---" << endl;
    gradLeader.displayInfo();
    collMember.displayInfo();
    cout << "\n";

    Project myProject("AI in Agricultural Waste", gradLeader, collMember);
    cout << "--- Project Info (Composition) ---" << endl;
    myProject.displayProjectInfo();
    cout << "\n";

    cout << "--- Polymorphism Demo ---" << endl;
    vector<Student*> team;
    team.push_back(&gradLeader);
    team.push_back(&collMember);

    for (const Student* s : team) {
        s->displayInfo();
    }

    return 0;
}
