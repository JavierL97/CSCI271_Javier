#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

enum class Course {
    Chinese,
    Math,
    English,
    Physics
};

string courseToString(Course c) {
    switch (c) {
        case Course::Chinese: return "Chinese";
        case Course::Math: return "Math";
        case Course::English: return "English";
        case Course::Physics: return "Physics";
        default: return "Unknown";
    }
}

struct StudentScore {
    string name;
    Course course;
    double score;
};

int main() {
    vector<StudentScore> scoreList;

    cout << "===== Step 1: Add student scores =====" << endl;

    scoreList.push_back({"Alice", Course::Math, 95});
    scoreList.push_back({"Brian", Course::Chinese, 88});
    scoreList.push_back({"Carol", Course::English, 92});
    scoreList.push_back({"David", Course::Math, 85});
    scoreList.push_back({"Emma", Course::Physics, 79});
    scoreList.push_back({"Frank", Course::Math, 98});
    scoreList.push_back({"Grace", Course::English, 89});

    cout << "Total records added: " << scoreList.size() << endl;

    cout << "\n===== Step 2: Print all scores (original order) =====" << endl;
    for (const auto& s : scoreList) {
        cout << "Name: " << s.name
             << " | Course: " << courseToString(s.course)
             << " | Score: " << s.score << endl;
    }

    sort(scoreList.begin(), scoreList.end(),
         [](const StudentScore& a, const StudentScore& b) {
             return a.score > b.score;
         });

    cout << "\n===== Step 3: Sort scores in descending order =====" << endl;
    for (const auto& s : scoreList) {
        cout << "Name: " << s.name
             << " | Course: " << courseToString(s.course)
             << " | Score: " << s.score << endl;
    }

    cout << "\n===== Step 4: Filter Math scores and compute average =====" << endl;

    double mathSum = 0;
    int mathCount = 0;

    for (const auto& s : scoreList) {
        if (s.course == Course::Math) {
            cout << "Name: " << s.name
                 << " | Score: " << s.score << endl;
            mathSum += s.score;
            mathCount++;
        }
    }

    cout << fixed << setprecision(1);

    if (mathCount > 0) {
        cout << "Math average score: " << (mathSum / mathCount) << endl;
    }

    cout << "\n===== Step 5: Compute overall average score =====" << endl;

    double totalSum = 0;
    for (const auto& s : scoreList) {
        totalSum += s.score;
    }

    cout << "Overall average score (all courses): "
         << (totalSum / scoreList.size()) << endl;

    return 0;
}
