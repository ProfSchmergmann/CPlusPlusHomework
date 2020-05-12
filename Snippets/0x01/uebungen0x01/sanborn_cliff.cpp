//
// Created by sberg on 16.04.2020.
//
#include <iostream>

using namespace std;

void array_out(double arr[], int length);

int main() {
    double arr[3]{1.0, 2.0};
    arr[2] = arr[0] + arr[1];
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << endl;
    }
    double arr2[3];
    for (int i=0; i<3; i++) {
        arr2[i] = arr[i];
    }
    array_out(arr,3);
}

void array_out(double arr[], int length) {
    for(int i=0; i<length; i++) {
        cout << arr[i] << endl;
    }
}

/*
 * Aufgabe:
 *
 *  • Legen Sie ein Array der Länge 3 vom Typ ’double’ an und initialisieren Sie die ersten
        beiden Elemente mit den Werten 1.0 und 2.0.
    • Speichern Sie die Summe in dem dritten Element.
    • Geben Sie alle Elemente aus.
    • Legen Sie ein weiteres Array der gleichen Größe an und kopieren Sie das erste in das
        zweite Array.
    Erweiterung:
    • Übergeben Sie das Feld einer Funktion zur Ausgabe. Beachten Sie, dass Sie die Länge
        mit übergeben müssen.
 */