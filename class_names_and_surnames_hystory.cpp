#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_Name[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_Name[year] = last_name;
  }
  string GetFullName(int year) {
    string fn = "", ln = "";
    int max_year = 0;
    for (const auto& fname : first_Name) {
        if (fname.first > max_year && fname.first <= year) {
            max_year = fname.first;
            fn = fname.second;
        }
    }
    max_year = 0;
    for (const auto& lname : last_Name) {
        if (lname.first > max_year && lname.first <= year) {
            max_year = lname.first;
            ln = lname.second;
        }
    }

    if (fn == "" && ln == "") {
        return "Incognito";
    }
    else {
        if (fn == "") {
            return ln + " with unknown first name";
        }
        else if (ln == "") {
            return fn + " with unknown last name";
            }
        else
            return fn + " " + ln;
    }
  }
private:
    map<int, string> first_Name;
    map<int, string> last_Name;
};
