#include <iostream>
#include <string>
#include <map>

using namespace std;

void Change_capital(map<string, string>& c, string country, string cap) {
    if (c.count(country) > 0) {
        if (c[country] == cap) {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        }
        else {
            string old_cap = c[country];
            c[country] = cap;
            cout << "Country " << country << " has changed its capital from " << old_cap << " to " << cap << endl;
        }
   }
    else {
        c[country] = cap;
        cout << "Introduce new country " << country << " with capital " << cap << endl;
        }
}

void Rename (map<string, string>& c, string old_country, string new_country) {
    if (old_country == new_country || c.count(old_country) == 0 || c.count(new_country) == 1) {
            cout << "Incorrect rename, skip" << endl;
        }
    else {
        cout << "Country " << old_country << " with capital " << c[old_country] << " has been renamed to " << new_country << endl;
        c[new_country] = c[old_country];
        c.erase(old_country);
    }
}

void About(map<string, string>& c, string country) {
    if (c.count(country) > 0) {
        cout << "Country " << country << " has capital " << c[country] << endl;
    }
    else {
        cout << "Country " << country << " doesn't exist" << endl;
    }
}

int main() {
    int Q, i;
    cin >> Q;
    map<string, string> caps;

    for (i = 0; i < Q; i++) {
        string s;
        cin >> s;
        if (s == "CHANGE_CAPITAL") {
            string country, new_cap;
            cin >> country >> new_cap;
            Change_capital(caps, country, new_cap);
        }

        if (s == "RENAME") {
            string old_country, new_country;
            cin >> old_country >> new_country;
            Rename(caps, old_country, new_country);
        }

        if (s == "ABOUT") {
            string country;
            cin >> country;
            About(caps, country);
        }

        if (s == "DUMP") {
            if (caps.size() == 0) {
                cout << "There are no countries in the world" << endl;
            }
            else {
                for (auto item : caps) {
                    cout << item.first << "/" << item.second << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
