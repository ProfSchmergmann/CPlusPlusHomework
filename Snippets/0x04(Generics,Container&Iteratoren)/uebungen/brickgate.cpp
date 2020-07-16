//
// Created by Sven on 08.05.2020.
//

/**
 * Erweitern Sie Übung ’Oakberg’.
    • Nutzen Sie ’auto&’ in der ’range-based-for’-Schleife über den ’vector’ ’v’ und
        verdoppeln Sie den Wert jedes Elements.
    • Definieren einen eigenen Typ ’it_type’ als ’const_iterator’ des Vektors und geben Sie
        in einer Schleife über einen const_iterator ’it’ das jeweilige Element des Iterators aus.
    Beachten Sie: ’*it’ ist der Wert des Elements und ’cbegin’ und ’cend’ geben einen
    const_iterator zurück.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Anlegen des int-Feldes
    int a[]{1,3,5,7};
    // Anlegen des Vektors
    vector<int> v{1,3,5,7};

    // range-based-for-Schleife für den Vektor
    cout << "Range-based-for-Schleife für das Feld: " << endl;
    for (auto x : a) {
        cout << x << ", ";
    }
    cout << endl;

    // range-based-for-Schleife für den Vektor
    cout << "Range-based-for-Schleife mit auto& und verdoppeln jedes Wertes für den Vektor: " << endl;
    for (auto& x : v) {
        x = x*2;
        cout << x << ", ";
    }
    cout << endl;

    // range-based-for-Schleife für den Vektor
    cout << "Range-based-for-Schleife für den Vektor: " << endl;
    for (auto x : v) {
        cout << x << ", ";
    }
    cout << endl;

    // Definieren eines eigenen Typs
    cout << "For-Schleife für den Vektor v mit konstantem Iterator: " << endl;
    auto it_type{v.cbegin()};
    for(it_type; it_type != v.cend(); it_type++) {
        cout << *it_type << ", ";
    }
}