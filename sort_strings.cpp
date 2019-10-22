#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

bool myfunc (string s1, string s2) {
    int i = 0;
    int len = min(s1.size(), s2.size());
    for (i = 0; i < len; i++) {
        if (tolower(s1[i]) == tolower(s2[i]))
            continue;
        else
            return tolower(s1[i]) < tolower(s2[i]);
    }
    return s1.size() < s2.size();
}

int main() {
    int N;
    cin >> N;
    vector<string> lets(N);
    for (auto& letter : lets) {
        cin >> letter;
    }
    sort(begin(lets), end(lets), myfunc);
    for (const string& letter : lets)
        cout << letter << " ";
    cout << endl;
    return 0;
}
