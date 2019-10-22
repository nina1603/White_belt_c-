#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

NEXT
Если же в новом месяце меньше дней, дела со всех удаляемых дней необходимо будет переместить на последний день нового месяца.

*/

int main() {
    int Q, i;
    int curmonth = 0;
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> bus(31);
    for (auto busses: bus) {
        busses = "";
    }
    vector<int> ambus(31);
    ambus.assign(31, 0);
    string s;
    cin >> Q;
    for (i = 0; i < Q; i++) {
        cin >> s;
        if (s == "ADD") {
            int day;
            string ccase;
            cin >> day >> ccase;
            --day;
            ++ambus[day];
            if (bus[day] != "") {
                bus[day] += " ";
            }
            bus[day] += ccase;
        }

        if (s == "NEXT") {
            curmonth = (curmonth + 1) % 12;
            if (months[(curmonth - 1) % 12] <= months[curmonth]) {
                bus.resize(months[curmonth], "");
                ambus.resize(months[curmonth], 0);
            }
            else {
                for (size_t j = months[curmonth]; j < bus.size(); j++) {
                    if (bus[months[curmonth] - 1] != "") {
                        bus[months[curmonth] - 1] += " ";
                    }
                    bus[months[curmonth] - 1] += bus[j];
                    ambus[months[curmonth] - 1] += ambus[j];
                }
                bus.resize(months[curmonth]);
                ambus.resize(months[curmonth]);
            }
        }
        if (s == "DUMP") {
            int day;
            cin >> day;
            --day;
            cout << ambus[day] << " " << bus[day] << endl;
        }
    }
    return 0;
}
