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

vector<string> Find_Hystory_Name(const map<int, string>& m, const string& name, int year) {
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
  void ChangeFirstName(int year, const string& first_name) {
    first_Name[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_Name[year] = last_name;
  }
  string GetFullName(int year) {
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

  string GetFullNameWithHistory(int year) {
    string fn = Find_name(first_Name, year);
    string ln = Find_name(last_Name, year);
    if (fn != "") {
        vector<string> fnames = Find_Hystory_Name(first_Name, fn, year);
        if (fnames.size() > 0) {
            fn += " (";
            for (int i = fnames.size() - 1; i >= 0; i--) {
                fn += fnames[i];
                if (i > 0) fn += ", ";
            }
            fn += ")";
        }
    }
    if (ln != "") {
        vector<string> lnames = Find_Hystory_Name(last_Name, ln, year);
        if (lnames.size() > 0) {
            ln += " (";
            for (int i = lnames.size() - 1; i >= 0; i--) {
                ln += lnames[i];
                if (i > 0) ln += ", ";
            }
            ln += ")";
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
