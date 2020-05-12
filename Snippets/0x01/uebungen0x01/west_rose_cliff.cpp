//
// Created by sberg on 16.04.2020.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Geben Sie eine ganze Zahl ein!" << endl;
    cin >> n;
    char c;
    cout << "Geben Sie ein Zeichen ein!" << endl;
    cin >> c;
    bool isBiggerThanZero = n > 0;
    bool isCapitalLetter = (c > 64 && c < 91);
    if (isBiggerThanZero) {
        cout << "Die Zahl ist groesser als 0." << endl;
    } else {
        cout << "Die Zahl is kleiner oder gleich 0." << endl;
    }
    if (isCapitalLetter) {
        cout << "Der Buchstabe " << c << " ist gross." << endl;
    } else {
        cout << "Char c: " << c << " ist ein klein oder kein Buchstabe." << endl;
    }
    (isCapitalLetter) ? cout << "Der Buchstabe " << c << " ist gross." << endl : cout << "Char c: " << c << " ist ein klein oder kein Buchstabe." << endl;
}


/*
 * Aufgabe West Rose Cliff:
 *
 *  • Lesen Sie eine ganze Zahl ’n’ vom Typ ’int’ und ein Zeichen ’c’ vom Typ ’char’ ein.
    • Testen Sie, ob die Zahl ’n’ größer als 0 und ob das Zeichen ’c’ ein Großbuchstabe ist.
    • Definieren Sie bool’sche Variablen mit den Testergebnissen und geben diese aus.
        Erweiterung:
    • Nutzen Sie einmal, wenn möglich, den ’?’-Operator anstelle einer if-Abfrage.
 */
