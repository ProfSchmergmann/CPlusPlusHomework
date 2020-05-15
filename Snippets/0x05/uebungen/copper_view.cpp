//
// Created by Sven on 15.05.2020.
//
/**
 * ’Copper View’
    Variablen über Zeiger modifizieren.
        • Legen Sie eine ’int’- und eine ’float’-Variable an und initialisieren Sie sie mit
            beliebigen Werten.
        • Legen Sie zwei Zeiger an und initialisieren Sie sie so, dass sie jeweils auf diese
            beiden Variablen zeigen.
        • Verändern Sie die Werte der Variablen mit Hilfe der Zeiger.
        • Geben Sie jeweils den Zeiger, den Wert auf den er zeigt und die zugehörige Variable
            aus.
    Erweiterung:
        • Legen Sie einen Zeiger auf den Zeiger auf ’int’ an, initialisieren Sie ihn mit der
            Adresse Ihres ’int’-Zeigers und geben Sie den Wert der ’int’-Variablen hierüber aus.
 */

#include <iostream>

using namespace std;

int main() {

    int i{1};
    float f{2.0f};

    int* pInt{&i};
    float* pFloat{&f};

    int** ppInt{&pInt};

    cout << "i = " << i << ", f = " << f << endl;
    cout << "*pInt = " << pInt << ", pInt = " << *pInt << endl;
    cout << "*pFloat = " << pFloat << ", pFloat = " << *pFloat << endl;
    cout << "**ppInt = " << ppInt << ", *ppInt = " << *ppInt << ", ppInt = " << **ppInt << endl;
}
