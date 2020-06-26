//
// Created by Sven on 19.06.2020.
//

#include <iostream>
#include <functional>

using namespace std;

typedef double (*function_t)(int a, int b);

double evalf(int a, int b) {
    return (double) a / b;
}

int main() {

    function_t Q1 = evalf;

    int a{1};
    int b{3};
    cout << "Quotient von " << a << " und " << b << " : " << Q1(a, b) << endl;

    auto Q2 = function<double, (int , int) >;

    double A = Q2([](int a, int b) -> auto {return (double)a/b;});

    cout << "Quotient von " << a << " und " << b << " : " << Q2(a,b) << endl;

}
