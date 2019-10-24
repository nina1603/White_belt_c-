#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Specialization {
    explicit Specialization(const string& new_specialization) {
        value = new_specialization;
        }
        string value;
};
struct Week {
    explicit Week(const string& new_week) {
        value = new_week;
    }
    string value;
};
struct Course {
    explicit Course(const string& new_course) {
        value = new_course;
        }
    string value;
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle(const Specialization&(specialization_), const Course&(course_), const Week&(week_)) {
      specialization = specialization_.value;
      course = course_.value;
      week = week_.value;
  }
};

int main() {
    LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);
    cout << title.course;
    return 0;
}
