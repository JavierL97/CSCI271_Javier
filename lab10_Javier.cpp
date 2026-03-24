#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    string major;
    string hobby;
    double gpa;
    string email;
    string city;
};

void displayStudents(Student s[], int size) {
    for (int i = 0; i < size; i++) {
        cout << s[i].id << " "
             << s[i].name << " ("
             << s[i].major << ") - "
             << s[i].city << " - GPA: "
             << s[i].gpa << endl;
    }
}

// Count GPA >= 3.0
int countHighGPA(Student s[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (s[i].gpa >= 3.0)
            count++;
    }
    return count;
}

void displayByCity(Student s[], int size, string cityName) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (s[i].city == cityName) {
            cout << s[i].name << " ("
                 << s[i].major << ", GPA "
                 << s[i].gpa << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No students found in that city." << endl;
    }
}

int main() {
    const int MAX = 10;
    Student students[MAX];
    int count = 3;

    students[0] = {"S01", "Tom", "MATH", "Football", 2.8, "tom@google.com", "Modesto"};
    students[1] = {"S02", "Alice", "CS", "Reading", 3.5, "alice@google.com", "Modesto"};
    students[2] = {"S03", "Scott", "CS", "Basketball", 3.2, "scott@google.com", "SanJose"};

    ofstream outFile("students.txt");
    for (int i = 0; i < count; i++) {
        outFile << students[i].id << " "
                << students[i].name << " "
                << students[i].major << " "
                << students[i].hobby << " "
                << students[i].gpa << " "
                << students[i].email << " "
                << students[i].city << endl;
    }
    outFile.close();

    cout << "[1] Data saved to students.txt" << endl;

    ifstream inFile("students.txt");
    Student newStudents[MAX];
    int newCount = 0;

    while (inFile >> newStudents[newCount].id
                  >> newStudents[newCount].name
                  >> newStudents[newCount].major
                  >> newStudents[newCount].hobby
                  >> newStudents[newCount].gpa
                  >> newStudents[newCount].email
                  >> newStudents[newCount].city) {
        newCount++;
    }
    inFile.close();

    cout << "[2] Loaded " << newCount << " students from students.txt\n" << endl;
    cout << "[3] Displaying all students:" << endl;
    cout << "-----------------------------------------" << endl;
    displayStudents(newStudents, newCount);

    int highGPA = countHighGPA(newStudents, newCount);
    cout << "\n[4] Students with GPA >= 3.0: " << highGPA << endl;

    string citySearch = "Modesto";
    cout << "\n[5] Students from " << citySearch << ":" << endl;
    displayByCity(newStudents, newCount, citySearch);

    cout << "\nProgram finished." << endl;

    return 0;
}
