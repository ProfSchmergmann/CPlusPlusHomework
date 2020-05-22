//
// Created by sberg on 22.05.2020.
//
/**
 * ’South Birds Gale’
    Zeigern, Felder
    • Definieren Sie vier Worte ’Dies’, ’ist’, ’ein’, ’Satz’ in einem Feld mit vier Zeigern.
    • Übergeben Sie dieses Feld von Zeigern einer Funktion, um dort die Worte in
        umgekehrter Reihenfolge auszugeben.
    Erweiterung:
    • Drehen Sie die die Reihenfolge der Worte in dem Feld vor der Ausgabe um (nicht die
        Worte selbst).
    • Drehen Sie auch die Worte selbst für die Ausgabe um.
 */

#include <iostream>

using namespace std;

void umgekehrteAusgabe(char *satz[], int size);

void cStringUmkehren(char *satz[], int size);

void worteUmkehren(char* wort, int size);

int main() {

    char *c1{"Dies"};
    char *c2{"ist"};
    char *c3{"ein"};
    char *c4{"Satz"};
    char *satz[4]{c1, c2, c3, c4};
    umgekehrteAusgabe(satz, 4);
    cStringUmkehren(satz, 4);
    for (int i = 0; i < 4; ++i) {
        for (const char *p = satz[i]; *p; p++) {
            cout << *p;
        }
        cout << endl;
    }
    worteUmkehren(satz[0], 4);
    cout << satz[0] << endl;

}

void umgekehrteAusgabe(char *satz[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        cout << satz[i] << endl;
    }
}

void cStringUmkehren(char *satz[], int size) {
    int j = size-1;
    int i = 0;
    while (i != j+1) {
        char *temp = satz[i];
        satz[i] = satz[j];
        satz[j] = temp;
        i++;
        j--;
    }
}

void worteUmkehren(char* wort, int size) {
    int j = size-1;
    int i = 0;
    while (i != j+1) {
        char *temp = &wort[i];
        &wort[i] = &wort[j];
        &wort[j] = temp;
        i++;
        j--;
    }
}