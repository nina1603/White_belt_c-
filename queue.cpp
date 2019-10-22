#include <iostream>
#include <string>
#include <vector>

using namespace std;

void come(vector<string>& q, int num) {
    if (num > 0) {
        for (int j = 0; j < num; j++) {
            q.push_back("quiet");
        }
    }
}

void worry_count(vector<string>& q) {
    int wornum = 0;
    for (size_t j = 0; j < q.size(); j++) {
        if (q[j] == "worry")
            ++wornum;
    }
    cout << wornum << endl;
}

void leave(vector<string>& q, int num) {
    for (int j = 0; j < -num; j++) {
        q.pop_back();
    }
}

int main() {
    int Q, num;
    string status;
    vector<string> que;
    cin >> Q;
    for (int i = 0 ; i < Q; i++) {
        cin >> status;
        if (status == "WORRY_COUNT") {
            worry_count(que);
        }
        else {
            cin >> num;
            if (status == "COME") {
                if (num > 0) {
                    come(que, num);
                }
                else {
                    leave(que, num);
                }
            }
            if (status == "WORRY") {
                que[num] = "worry";
            }
            if (status == "QUIET") {
                que[num] = "quiet";
            }
        }
    }
    return 0;
}
