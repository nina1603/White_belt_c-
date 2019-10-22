#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

string Find_name(const map<int, string>& m, int year) {
    string res = "";
    for (const auto& item : m) {
        if (item.first <= year) {
            res = item.second;
        }
        else
            break;
    }
    return res;
}

vector<string> Find_Hystory_Name(const map<int, string>& m, string& name, int year) {
    vector<string> res;
    for (const auto& item: m) {
        if (item.first < year) {
            res.push_back(item.second);
        }
        else
            break;
    }
    while (true) {
        if (res.size() > 0) {
            if (res[res.size() - 1] == name) {
                res.pop_back();
            }
            else break;
        }
        else break;
    }
    return res;
}

class Person {
public:
    Person (const string& name, const string& surname, int year) {
        birth_year = year;
        first_Name[year] = name;
        last_Name[year] = surname;
    }

  void ChangeFirstName(int year, const string& first_name) {
    if (year >= birth_year)
        first_Name[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    if (year >= birth_year)
        last_Name[year] = last_name;
  }
  string GetFullName(int year) const {
    if (year < birth_year)
        return "No person";
    string fn = Find_name(first_Name, year);
    string ln = Find_name(last_Name, year);
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
    string GetNameWithHistory(const map<int, string>& names, int year) const {
        string str = Find_name(names, year);
        if (str != "") {
            vector<string> name = Find_Hystory_Name(names, str, year);
            if (name.size() > 0) {
                str += " (";
                for (int i = name.size() - 1; i >= 0; i--) {
                    str += name[i];
                    if (i > 0) str += ", ";
                }
                str += ")";
            }
        }
        return str;
    }

  string GetFullNameWithHistory(int year) const {
    if (year < birth_year)
        return "No person";
    string fn = GetNameWithHistory(first_Name, year);
    string ln = GetNameWithHistory(last_Name, year);

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
    int birth_year;
};
