//
// Created by Sven on 27.05.2020.
//

/**
 * ’Green Mound’
    new, Felder, C-Strings
    • Programmieren Sie eine Funktion ’copy’, die einen C-String als Parameter erhält,
        dynamischen Speicher mit ’new’ anfordert, den übergebenen C-String dorthin inkl.
        des Null-Zeichens kopiert und den Zeiger auf den neuen Speicher zurückgibt.
    • Ermitteln Sie die Länge mit Hilfe einer eigenen Funktion. Schreiben Sie Testcode, der
        Worte kopiert und ausgibt.
    Erweiterung:
    • Schreiben Sie eine Funktion ’free’ zum Freigeben des zuvor reservierten Speichers
        und nutzen Sie sie.
    • Testen Sie ggf. mit Tools wie valgrind, ob Ihr Code Speicherlecks enthält.
 */

#include <iostream>

using namespace std;

char *copy(char *cString);

int length(char *cString);

void free(char *cString);

int main() {
    char *s = "Hallo";
    for (const char *p = s; (*p); p++) {
        cout << *p;
    }
    cout << endl;
    char *temp = copy(s);
    for (const char *p = temp; *p; p++) {
        cout << *p;
    }
    cout << endl;
    free(temp);
}

char *copy(char *cString) {
    char *temp = new char[length(cString)];
    int i = 0;
    for (const char *p = cString; *p; p++) {
        temp[i] = *p;
        i++;
    }
    return temp;
}

int length(char *cString) {
    int length = 0;
    for (const char *p = cString; *p; p++) {
        length++;
    }
    return length;
}

void free(char *cString) {
    delete[] cString;
}