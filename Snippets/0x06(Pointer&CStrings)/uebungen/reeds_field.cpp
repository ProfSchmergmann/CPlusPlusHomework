//
// Created by sberg on 22.05.2020.
//
/**
 * ’Reeds Field’
    C-String
    • Legen Sie einen C-String mit einem beliebigen Text an: char* str = ”hallo”;
    • Legen Sie einen Zeiger auf char an und laufen Sie mit diesem durch das Feld str
        (einschließlich des Null-Zeichens), um den jeweiligen Charakter, auf den der Zeiger
        zeigt, auszugeben. Geben Sie den jeweils aktuellen Charakter einmal als Charakter
        und einmal als ASCII Wert aus. Tipp: (int)-cast für den ASCII-Wert,
    Erweiterung:
    • Geben Sie zusätzlich auch den Wert des Zeigers, d.h. die Adresse aus. Tipp:
        geeigneter cast.
 */

#include <iostream>

using namespace std;

int main() {

    char *str = "hallo";

    // Ich weiss leider nicht, wie man das Nullzeichen am Ende ausgeben soll.
    for (const char *p = str; *p; p++) {
        cout << *p << " : ASCII-Wert: " << (int) (*p);
        cout << ", Zeiger: " << (void *) p << endl;
    }
}
