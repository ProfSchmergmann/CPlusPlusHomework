//
// Created by Sven on 29.05.2020.
//
/**
 * Operatoren
    • Implementieren Sie eine generische Klasse ’fastvector’, die einen mathematischen
        Vektor von Koeffizienten einer festen Dimension modelliert, mit dem man rechnen
        kann.
    • Nutzen Sie intern ein ’array’ fester Länge. Die Dimension und der Typ werden durch
        die Template-Parameter bestimmt.
    • Grundsätzlich soll addiert, subtrahiert und mit einem Skalar multipliziert werden
        können. Natürlich kann man auch einzelne Koeffizienten lesen und setzen.
    • Implementieren Sie geeignete Operatoren bzw. Funktionen, so dass folgende
        Codeschnipsel für eine ’fastvector’-Instanz ’v’, bzw. ’v1’ und ’v2’, funktionieren:
    • ’v=1;’ setzt alle Koeffizienten auf einen Wert, hier 1.
    • ’v1+v2’ addiert ’v1’ und ’v2’.
    • ’v1-v2’ subtrahiert ’v2’ von ’v1’.
    • ’v*3’ bzw. ’3*v’ multiplizieren v mit einem Skalar, hier 3.
    • ’-v’ negiert alle Koeffizienten.
    • ’v[i]’ liest bzw. schreibt den i’ten Koeffizienten.
    • ’cout « v;’ gibt die Koeffizienten von ’v’ aus.
        Testen Sie Ihren Code aussagekräftig.
 */

#include <iostream>
#include <array>

using namespace std;

template<typename T, size_t dim>
class fastvector {
    const std::size_t dim;
    array<T, dim> coeffs;

    fastvector(int dim, T t): m_dim{} {

    }
};

