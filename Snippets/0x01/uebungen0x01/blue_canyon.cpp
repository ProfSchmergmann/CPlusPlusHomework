//
// Created by sberg on 16.04.2020.
//

#include <iostream>

using namespace std;

int pot_for(int b, int p);

int pot_while(int b, int p);

int main() {
    int b;
    int p;
    cout << "Geben Sie eine Basis ein!" << endl;
    cin >> b;
    cout << "Geben Sie eine Potenz ein!" << endl;
    cin >> p;
    cout << "b hoch p mit for: " << pot_for(b, p) << endl;
    cout << "b hoch p mit while: " << pot_while(b, p) << endl;
}

int pot_for(int b, int p) {
    int res = b;
    for (int i{1}; i < p; i++) {
        res = res * b;
    }
    return res;
}

int pot_while(int b, int p) {
    int i{1};
    int res = b;
    do {
        res = res * b;
        i++;
    } while (i < p);
    return res;
}

/*
 * Aufgabe Blue Canyon:
 *
 * Berechnung von b^n:
    • Lesen Sie Variablen ’b’ und ’n’ eines geeigneten Typs ein. Berechnen Sie ’b hoch n’ in
        einer Schleife und geben Sie das Ergebnis aus.
    Erweiterung:
    • Schreiben Sie eine Funktion ’pot’, die ’b’ und ’n’ übergeben bekommt und das Ergebnis
        zurückgibt.
    • Definieren Sie die Funktion ’pot’ erst hinter main und geben Sie vor ’main’ nur die
        Signatur an.
    • Formulieren Sie die Schleife einmal als ’for’ und einmal als ’while’-Schleife.
 */
