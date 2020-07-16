//
// Created by Sven on 19.06.2020.
//
/**
 *  ’Roarport’
        Lambda-Ausdruck
            Schreiben Sie jeweils einen Lambda-Ausdruck, der
            • drei übergebene double-Werte addiert und zurückgibt;
            • testet, ob ein übergebener int-Wert in einem Intervall [a,b] liegt (dabei sind a und b
                lokale Variablen);
            • keine Argumente hat, aber eine lokale int-Variable z auf -z setzt (akademisches Bsp.).
 */

#include <iostream>

using namespace std;

typedef double (*function_t)(double x, double y, double z);

double evalf(function_t f, double x, double y, double z) {
    return f(x, y, z);
}

int main() {

    cout << "Function for adding three doubles: " << endl;

    double x{1};
    double y{2};
    double z{3};

    auto addingThreeDoubles = [](double x, double y, double z) { return x + y + z; };

    cout << "Adding " << x << ", " << y << ", " << z << endl;
    cout << "evalf(addingThreeDoubles, x,y,z) : " <<
         evalf(addingThreeDoubles, x, y, z) << endl;

    int a{0};
    int b{10};
    auto testforIntervall = [=](int x) { return (x >= a && x <= b); };
    int test{5};
    cout << "Is " << test << " in Intervall [" << a << ", " << b << "] ? " << endl;
    cout << ((testforIntervall(test)) ? "Yes" : "No") << endl;

    int m{6};
    auto negateInt = [&m]() { m = -m; };
    cout << "Negate " << m << ": " << endl;
    negateInt();
    cout << m << endl;

}
