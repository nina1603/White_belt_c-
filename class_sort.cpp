#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    strings.push_back(s);
  }
  vector<string> GetSortedStrings() {
    vector<string> res = strings;
    sort(begin(res), end(res));
    return res;
  }
private:
  vector<string> strings;
};
