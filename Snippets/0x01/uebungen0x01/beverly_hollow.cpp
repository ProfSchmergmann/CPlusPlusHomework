//
// Created by sberg on 16.04.2020.
//

#include <iostream>

using namespace std;

int fib_it(int n);

int fib_rek(int n);

int main() {

    int n;
    cout << "Geben Sie eine ganze Zahl ein!" << endl;
    cin >> n;
    cout << "Iterativ: Die ersten " << n << " Fibonacci Zahlen sind: " << endl;
    for (int i = 0; i < n; i++) {
        cout << fib_it(i) << endl;
    }
    cout << "Rekursiv: Die ersten " << n << " Fibonacci Zahlen sind: " << endl;
    for (int i = 0; i < n; i++) {
        cout << fib_rek(i) << endl;
    }

}

int fib_it(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        int a = 1;
        int b = 1;
        int c;
        for (int i = 1; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

int fib_rek(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib_rek(n-1) + fib_rek(n-2);
    }
}

/*
 * Aufgabe:
 *
 * Berechnung der Fibonacci-Folge (fi):
    • Lesen Sie eine ganze Zahl ’n’ von der Konsole ein.
    • Berechnen Sie die ersten ’n’ Fibonaccizahlen fi iterativ, d.h. in einer Schleife (also
        nicht rekursiv) und geben Sie sie aus.
        Die Vorschrift lautet: fi = fi−1 + fi−2 mit f0 = f1 = 1.
    Erweiterung:
    • Berechnen Sie die Zahlen fi jeweils rekursiv.
    • Überlegen Sie: Welcher Ansatz ist (vermutlich) schneller und warum?
 */