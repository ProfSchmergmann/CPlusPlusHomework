//
// Created by Sven on 24.04.2020.
//

#include <iostream>

using namespace std;

class kontakt {
    unsigned int m_alter;
    string m_name;

public:
    kontakt() : m_alter{}, m_name{"-"} {
    };

    void alter(unsigned int alter) {
        m_alter = alter;
    }

    void name(const string& name) {
        m_name = name;
    }

    [[nodiscard]] unsigned int alter() const {
        return m_alter;
    }

    [[nodiscard]] string name() const {
        return m_name;
    }

    kontakt(unsigned int alter, const string& name) : m_alter{alter}, m_name{name} {
    }

    kontakt(const kontakt &kontakt) = default;

    ~kontakt() {
    }

};

ostream& operator<<(ostream& os, const kontakt& kontakt) {
    os << "Alter: " << kontakt.alter() << ", Name: " << kontakt.name();
    return os;
}

int main() {
    cout << "---" << __FILE__ << "---" << endl;

    string a{"baby"};
    kontakt k1;
    kontakt k2{1, a};
    kontakt k3{k2};

    cout << "k1: " << k1 << endl;
    cout << "k2: " << k2 << endl;
    cout << "k3: " << k3 << endl;

    k3.name("zweites baby");

    cout << "k3: " << k3 << endl;
}

/**
 * ’Lucky Rock’
Eine Klasse ’kontakt’ mit Alter und Namen entwerfen.
• Implementieren Sie einen default-ctor und einen dtor.
• Implementieren Sie einen ctor, der ein ganzzahliges Alter vom Typ ’unsigned int’ und
einen Namen vom Typ ’string’ übergeben bekommt. Nutzen Sie ’:’ zur Initialisierung.
• Implementieren Sie ’getter’ und ’setter’.
• Schreiben Sie aussagekräftigen Testcode.
Erweiterung:
• Implementieren Sie einen copy-ctor.
• Implementieren Sie einen operator ’«’ zur Ausgabe.
• Verwenden Sie so oft wie möglich ’const’.
 *
 */
