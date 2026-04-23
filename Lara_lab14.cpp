#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

enum class Course {
    Chinese,
    Math,
    English,
    Physics,
    Chemistry
};

struct StudentScore {
    std::string name;
    Course course;
    double score;
};

std::string courseToString(Course course) {
    switch (course) {
        case Course::Chinese: return "Chinese";
        case Course::Math: return "Math";
        case Course::English: return "English";
        case Course::Physics: return "Physics";
        case Course::Chemistry: return "Chemistry";
        default: return "Unknown course";
    }
}

int main() {
    std::vector<StudentScore> scoreList;

    std::cout << "===== Step 1: Add student scores =====\n";
    scoreList.push_back({"Alice", Course::Math, 95});
    scoreList.push_back({"Brian", Course::Chinese, 88});
    scoreList.push_back({"Carol", Course::English, 92});
    scoreList.push_back({"David", Course::Math, 85});
    scoreList.push_back({"Emma", Course::Physics, 79});
    scoreList.push_back({"Frank", Course::Math, 98});
    scoreList.push_back({"Grace", Course::English, 89});

    std::cout << "Total records added: "
              << scoreList.size() << "\n\n";

    std::cout << "===== Step 2: Print all scores (original order) =====\n";
    for (const auto& s : scoreList) {
        std::cout << "Name: " << s.name
                  << " | Course: " << courseToString(s.course)
                  << " | Score: " << s.score << "\n";
    }
    std::cout << "\n";

    std::cout << "===== Step 3: Sort scores in descending order =====\n";
    std::sort(scoreList.begin(), scoreList.end(),
              [](const StudentScore& a, const StudentScore& b) {
                  return a.score > b.score;
              });

    for (const auto& s : scoreList) {
        std::cout << "Name: " << s.name
                  << " | Course: " << courseToString(s.course)
                  << " | Score: " << s.score << "\n";
    }
    std::cout << "\n";

    std::cout << "===== Step 4: Filter Math scores and compute average =====\n";

    double mathSum = 0;
    int mathCount = 0;

    for (const auto& s : scoreList) {
        if (s.course == Course::Math) {
            std::cout << "Name: " << s.name
                      << " | Score: " << s.score << "\n";
            mathSum += s.score;
            mathCount++;
        }
    }

    std::cout << std::fixed << std::setprecision(1);

    if (mathCount > 0) {
        std::cout << "Math average score: "
                  << (mathSum / mathCount) << "\n";
    }
    std::cout << "\n";

    std::cout << "===== Step 5: Compute overall average score =====\n";

    double totalSum = 0;
    for (const auto& s : scoreList) {
        totalSum += s.score;
    }

    std::cout << "Overall average score (all courses): "
              << (totalSum / scoreList.size()) << "\n";

    return 0;
}
