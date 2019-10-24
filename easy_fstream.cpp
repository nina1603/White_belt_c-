#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    /*if (input.is_open()) {
        string line;
        while(getline(input, line)) {
        cout << line << endl;
        }
    }
    else {
        cout << "Error" << endl;
    }*/
    ofstream output("output.txt");
    if (input.is_open()) {
        string line;
        while(getline(input, line)) {
        output << line << endl;
        }
    }
    else {
        cout << "Error" << endl;
    }
    return 0;
}
