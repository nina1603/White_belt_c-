#include <iostream>
#include <cmath>
using namespace std;

int determ() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            return 0;
        }
        else {
            double x1 = - c / b;
            cout << x1 << endl;
        }
    }
    else {
        double det = b*b - 4*a*c;
        if (det < 0) {
            return 0;
        }
        double x1 = (-b + sqrt(det)) / (2*a);
        double x2 = (-b - sqrt(det)) / (2*a);
        if (x1 == x2) {
            cout << x1 << endl;
        }
        else {
            cout << x1 << " " << x2;
        }
    }
    return 0;
}
