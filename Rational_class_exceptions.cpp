#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <exception>
#include <stdexcept>

using namespace std;

int eucl (int x, int y) { // x > y
    if (x % y == 0) {
        return y;
    }
    else {
        int temp = x % y;
        return eucl(y, temp);
    }
}

class Rational {
public:
    Rational() {
        numer = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator must not be 0.");
        }
        if (denominator < 0) {
            numerator = - numerator;
            denominator = - denominator;
        }
        if (numerator == 0) {
            numer = numerator;
            denom = 1;
        }
        else {
            int nod = eucl(max(abs(numerator), abs(denominator)), min(abs(numerator), abs(denominator)));
            numer = numerator / nod;
            denom = denominator / nod;
        }
    }

    int Numerator() const {
        return numer;
    }

    int Denominator() const {
        return denom;
    }

private:
    int numer;
    int denom;
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator()* rhs.Denominator() - lhs.Denominator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator()* rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Divisor must not be 0.");
    }
    return {lhs.Numerator()* rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};

}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
