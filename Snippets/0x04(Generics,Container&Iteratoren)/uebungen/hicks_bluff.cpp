//
// Created by Sven on 08.05.2020.
//

/**
 * Suchen und löschen in Datencontainern mit Iteratoren.
       • Suchen Sie in dem Vektor ’{1,2,3,4,5}’ das Element ’2’ und geben Sie die nächsten
            drei Elemente (inkl.) aus (wenn vorhanden).
    • Legen Sie folgende ’unordered_map’ an
            ’{ 1→’Eins’, ..., 5→’Fünf’ }’ und suchen Sie dort nach dem Schlüssel ’2’.
    • Löschen Sie in obiger Map alle Elemente, deren Schlüssel größer ist als ’2’.
    Erweiterung:
    • Nutzen Sie ’auto’ so oft wie möglich.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> v{1,2,3,4,5};

    // Iterator für find
    cout << "Ausgabe des Vektors ab dem Element 2: " << endl;
    auto it_v = find(v.begin(), v.end(), 2);
    for (it_v; it_v != v.end(); it_v++) {
        cout << *it_v << ", ";
    }
    cout << endl;

    // Konstruieren einer unordered Map
    cout << "Unordered map: " << endl;
    unordered_map<int, string> unorderedMap{{1, "Eins"},
                                  {2, "Zwei"},
                                  {3, "Drei"},
                                  {4, "Vier"},
                                  {5, "Fünf"}};
    for (const auto& x : unorderedMap) {
        cout << x.first << ", " << x.second << endl;
    }

    for (auto it = unorderedMap.begin(); it != unorderedMap.end(); it++) {
        if (it->first > 2) {
            unorderedMap.erase(it);
        }
    }

    cout << "Map after deletion: " << endl;

    for (auto x : unorderedMap) {
        cout << x.first << ", " << x.second << endl;
    }

}