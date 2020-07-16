//
// Created by sberg on 17.04.2020.
//

#include <iostream>
#include <array>

using namespace std;

const int dim = 3;

// Struct polynom which saves the coefficients like
// coeffs[0] * x^0 + coeffs[1] * x^1 + coeffs[2] * x^2.
struct polynom {
    array<signed int, dim> coeffs;

    friend ostream &operator<<(ostream &os, const polynom &p);

};

double eval(const polynom &p, int x);

int main() {
    polynom p{1, 2, 3};
    cout << "Function p: y(x) = " << p << endl;
    cout << "Value of p at x = 0: " << eval(p, 0) << endl;
    cout << "Value of p at x = 1: " << eval(p, 1) << endl;
    cout << "Value of p at x = 2: " << eval(p, 2) << endl;

    polynom p2{-1, -2, -3};
    cout << "Function p2: y(x) = " << p2 << endl;
    cout << "Value of p2 at x = 0: " << eval(p2, 0) << endl;
    cout << "Value of p2 at x = 1: " << eval(p2, 1) << endl;
    cout << "Value of p2 at x = 2: " << eval(p2, 2) << endl;
}

double eval(const polynom &p, int x) {
    return (p.coeffs.at(0)
            + p.coeffs.at(1) * x
            + p.coeffs.at(2) * (x * x));
}

ostream &operator<<(ostream &os, const polynom &p) {
    (p.coeffs.at(0) >= 0) ? os << "+ " : os << "- ";
    os << abs(p.coeffs.at(0));
    (p.coeffs.at(1) >= 0) ? os << " + " : os << " - ";
    os << abs(p.coeffs.at(1)) << "*x";
    (p.coeffs.at(2) >= 0) ? os << " + " : os << " - ";
    os << abs(p.coeffs.at(2)) << "*x^2";
    return os;
}