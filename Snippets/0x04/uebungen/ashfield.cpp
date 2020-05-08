//
// Created by Sven on 08.05.2020.
//

/**
 * Mapping von ISBN-Nummern zu Büchern.
        • Implementieren Sie ein ’struct’ ’buch’, welches (vereinfacht) einen Autor und einen
            Titel enthält.
        • Definieren Sie einen eigenen Typ ’katalog_t’ durch eine ’unordered_map’, die einen
            ’string’ (ISBN) auf ein ’buch’ abbildet. Legen Sie eine Variable ’katalog’ dieses Typs an.
        • Füllen Sie ’katalog’ mit drei echten Büchern (und ISBN) Ihrer Wahl, z.B. ’44245381X’
            → {’Walter Moers’,’Die 13 1/2 Leben des Käpt’n Blaubär’}, ...
        • Suchen Sie in einer Schleife mit ’const auto&’ alle Bücher, deren Titel länger als 30
            Zeichen ist und geben Sie diese aus.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct buch{
    string autor;
    string titel;
};

int main() {

    // Unordered map erstellen
    typedef unordered_map<string, buch> katalog_t;
    katalog_t katalog;
    katalog.insert({"978-3-662-43810-7", {"Chrisian Karpfinger", "Höhere Mathematik in Rezepten"}});
    katalog.insert({"978-3-8440-6079-9", {"Christof Schelthoff", "Analysis 2"}});
    katalog.insert({"978-3-8440-6078-2", {"Christof Schelthoff", "Analysis 1"}});

    for(const auto& x : katalog) {
        if (x.second.titel.size() > 20) {
            cout << "{" << x.first << ", " << x.second.autor << ", " << x.second.titel << "}" << endl;
        }
    }
}
