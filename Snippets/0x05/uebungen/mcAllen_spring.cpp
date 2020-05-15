//
// Created by Sven on 15.05.2020.
//
/**
 * ’McAllen Spring’
    Illegal – beachten Sie auch das Snippet zum Thema...
        • Versuchen Sie, durch Verwendung von Zeigern einzelne Bytes von lokalen ’int’-
            Variablen zu manipulieren. Nutzen Sie dafür casts in ’char*’.
        • Verändern Sie einzelne Bytes eines Texts der Form: char* p=”huhu”;
        Was passiert?
    Erweiterung:
        • Versuchen Sie, über Zeiger-Manipulationen lokale Variablen gezielt auf dem Stack zu
            verändern, ohne diese direkt zu adressieren.
    Tipp: Ermitteln Sie zunächst die Adresse einer lokalen Variablen. Die anderen liegen
        ’in der Nähe’.
 */

#include <iostream>

using namespace std;

int main() {

    int i1{1};
    int i2{2};

    cout << "i1 = " << i1 << ", &i1 = " << &i1 << endl;
    cout << "i2 = " << i2 << ", &i2 = " << &i2 << endl;

    int *pi1{&i1};

    *(pi1 - 1) = 9;

    cout << "i1 = " << i1 << endl;
    cout << "i2 = " << i2 << endl;

    char *pic1 = (char *) pi1;
    *(pic1 - 1) = 1;

    cout << "i1 = " << i1 << endl;
    cout << "i2 = " << i2 << endl;

    int *pi2{&i2};

    *(pi2 + 1) = 5;

    cout << "i1 = " << i1 << endl;
    cout << "i2 = " << i2 << endl;
}
