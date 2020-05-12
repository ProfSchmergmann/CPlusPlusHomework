//
// Created by sberg on 16.04.2020.
//

#include <iostream>
#include <cmath>

using namespace std;

bool isPrim(int n);

int main() {
    int n;
    cout << "Geben Sie eine Zahl ein!" << endl;
    cin >> n;
    cout << "Die Zahl " << n << " ist ";
    (isPrim(n)) ? cout << "eine" : cout << "keine";
    cout << " Primzahl.";
}

bool isPrim(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


/*
 * Aufgabe:
 *
 * Primzahlberechnung:
    • Lesen Sie eine ganze Zahl ’n’ von der Konsole ein.
    • Bestimmen Sie in einer Schleife über alle Zahlen 2 bis ’n’, ob die jeweilige Zahl eine
        Primzahl ist oder nicht. Geben Sie die jeweilige Zahl aus, wenn sie eine Primzahl ist.
    Erweiterung:
    • Schreiben Sie eine Funktion ’isPrim’, die eine Zahl übergeben bekommt und ’true’
        oder ’false’ zurück gibt.
    • Definieren Sie die Funktion ’isPrim’ nach ’main’ und geben Sie vor ’main’ nur die
        Signatur an.
 */