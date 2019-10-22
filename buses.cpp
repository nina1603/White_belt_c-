#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void Buses_for_stop(map<string, vector<string>>& c, string stop, vector<string>& order) {
    bool is_stop = false;
    bool is_bus = false;
    vector<string> b;
    for (auto busstops : c) {
        for (auto stops : busstops.second) {
            if (stops == stop) {
                b.push_back(busstops.first);
                is_bus = true;
                is_stop = true;
                break;
            }
        }
    }

    for (size_t h = 0; h < order.size(); h++) {
        for (auto bu : b) {
            if (order[h] == bu) {
                cout << bu << " ";
                break;
            }
        }
    }

    if (is_bus)
        cout << endl;
    if (!is_stop)
        cout << "No stop" << endl;
}

void Stops_for_bus(map<string, vector<string>>& c, string bus, vector<string>& order) {
    if (!c.count(bus)) {
        cout << "No bus" << endl;
    }
    else {
        for (auto stop : c[bus]) {
            vector<string> b;
            bool flag = false;
            cout << "Stop " << stop << ": ";
            for (auto otbus : c) {
                if (otbus.first != bus) {
                    for (size_t s = 0; s < otbus.second.size(); s++) {
                        if (otbus.second[s] == stop) {
                            b.push_back(otbus.first);
                            flag = true;
                            break;
                        }
                    }
                }
            }
            for (size_t h = 0; h < order.size(); h++) {
                for (auto bu : b) {
                    if (order[h] == bu) {
                        cout << bu << " ";
                        break;
                    }
                }
            }
            if (flag == false)
                cout << "no interchange";
            cout << endl;
        }
    }
}

void All_buses(map<string, vector<string>>& c) {
    if (c.empty()) {
        cout << "No buses" << endl;
    }
    else {
        for (auto bus : c) {
            cout << "Bus " << bus.first << ": ";
            for (auto stops : bus.second) {
                cout << stops << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int Q, i;
    cin >> Q;
    map<string, vector<string>> buses;
    vector<string> order;

    for (i = 0; i < Q; i++) {
        string s;
        cin >> s;
        if (s == "NEW_BUS") {
            string bus, stop;
            int stop_count;
            cin >> bus >> stop_count;
            order.push_back(bus);
            vector<string> stops(stop_count);
            for (int j = 0; j < stop_count; j++) {
                cin >> stop;
                buses[bus].push_back(stop);
            }
        }

        if (s == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            Buses_for_stop(buses, stop, order);
        }

        if (s == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            Stops_for_bus(buses, bus, order);
        }

        if (s == "ALL_BUSES") {
            All_buses(buses);
        }
    }
    return 0;
}
