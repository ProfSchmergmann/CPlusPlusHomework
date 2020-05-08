//
// Created by Sven on 08.05.2020.
//

/**
 * ’Oakberg’
       Datencontainer ’range-based-for’ durchlaufen und ’auto’ verwenden.
        • Definieren Sie ein ’int’-Feld ’a’, initialisiert mit den Werten 2, 3, 5, 7, sowie einen
            ’vector’ ’v’, initialisiert mit den selben Werten.
        • Durchlaufen Sie ’a’ und ’v’ jeweils in einer ’range-based-for’-Schleife mit ’auto’ und
            geben Sie das jeweilige Element aus.
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
    cout << "Range-based-for-Schleife für den Vektor: " << endl;
    for (auto x : v) {
        cout << x << ", ";
    }
 }
