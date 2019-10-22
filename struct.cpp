#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Incognizable {
    int x = 0;
    int y = 0;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    cout << a.x << " " << a.y << endl;
    cout << d.x << " " << d.y << endl;
    return 0;
}
