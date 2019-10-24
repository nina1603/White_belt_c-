#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    double digit;
    cout << fixed << setprecision(3);
    while (input >> digit) {
        cout << digit << endl;
    }
    return 0;
}
