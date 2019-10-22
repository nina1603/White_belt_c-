#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, i;
    vector<int> nums;
    int n;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> n;
        nums.push_back(n);
    }
    sort(begin(nums), end(nums), [](int x, int y){return (abs(x) <= abs(y));});
    for (const int& num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}
