#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int Q, i, n, it = 1;
    cin >> Q;
    map<vector<string>, int> bus;

    for (i = 0; i < Q; i++) {
        cin >> n;
        vector<string> stops(n);
        for (int j = 0; j < n; j++) {
            cin >> stops[j];
        }
        if (!bus.count(stops)) {
            bus[stops] = it;
            cout << "New bus " << it << endl;
            it++;
        }
        else {
            cout << "Already exists for " << bus[stops] << endl;
        }
    }
    return 0;
}
