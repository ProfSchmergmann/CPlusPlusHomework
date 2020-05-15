//
// Created by Sven on 15.05.2020.
//
/**
 * ’Kengate’
    Swap.
        • Schreiben Sie eine Funktion ’swap’, die zwei übergebene ’double’-Zahlen tauscht.
            Implementieren Sie die Funktionen einmal über Zeiger und einmal über Referenzen.
    Erweiterung:
        • Schreiben Sie eine weitere Funktion ’swap_ptr’, die zwei übergebene ’double’-Zeiger
            tauscht (Zeiger und Referenzen).
        • Testen Sie Ihren Code entsprechend.
 */

#include <iostream>

using namespace std;

void swapByPointer(double *d1, double *d2);

void swapByReferences(double &d1, double &d2);

/**
 * Die zu schreibende Funktion swap_ptr verstehe ich nicht so richtig,
 * da man das ja quasi schon in den vorherigen Funktionen realisiert hat.
 * Ausserdem kann man ja keine Werte uebergeben und die dann in einer Funtkion sinnvoll tauschen,
 * da die Speicheradresse nicht uebergeben wird.
 * @return ?
 */

//void swap_ptr(double *d1, double *d2);

int main() {
    double d1{1};
    double d2{2};

    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
    swapByPointer(&d1, &d2);
    cout << "Swap d1 and d2 by Pointer: " << endl;
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
    swapByReferences(d1, d2);
    cout << "Swap back d1 and d2 by References : " << endl;
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
//    double* p1{&d1};
//    double* p2{&d2};
//    swap_ptr(p1, p2);
//    cout << "Swap the pointers from d1 and d2: " << endl;
//    cout << "p1 = " << p1 << ", *p1 = " << *p1 << ", d1 = " << d1 << endl;
//    cout << "p2 = " << p2 << ", *p2 = " << *p2 << ", d2 = " << d2 << endl;
}


void swapByPointer(double *d1, double *d2) {
    double temp{*d1};
    *d1 = *d2;
    *d2 = temp;
}

void swapByReferences(double &d1, double &d2) {
    double temp{d1};
    d1 = d2;
    d2 = temp;
}


