#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    int N, M, i, j;
    ifstream input("input.txt");
    input >> N >> M;
    vector<int> digits(M);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            input >> digits[j];
            cout << setw(10) << digits[j];
            if (j != M - 1){
                input.ignore(1);
                cout << " ";
            }
        }
        if (i < N - 1)
            cout << endl;
    }
    return 0;
}
