//
// Created by Sven on 24.04.2020.
//

#include <iostream>

using namespace std;

class fraction {
    int m_num;
    int m_denum;

public:

    // Default Konstruktor, siehe Aufgabenstellung
    fraction() : m_num{}, m_denum{} {};

    // Konstruktor, welcher beide Variablen setzt
    fraction(const int& num, const int& denum) : m_num{num}, m_denum{denum} {
    }

    // Getter fuer das Attribut m_num
    [[nodiscard]] int num() const {
        return m_num;
    }

    // Setter fuer das Attribut m_num
    void num(const int& num) {
        m_num = num;
    }

    // Getter fuer das Attribut m_denum
    [[nodiscard]] int denum() const {
        return m_denum;
    }

    // Setter fuer das Attribut m_denum
    void denum(const int& denum) {
        m_denum = denum;
    }

    // Copy - Konstruktor
   fraction(const fraction& fraction) : m_num{fraction.num()}, m_denum{fraction.denum()}{
    }

    // Default Destructor, siehe Aufgabenstellung
    ~fraction() = default;

};

ostream &operator<<(ostream& os, const fraction& fraction) {
    os << fraction.num() << "/" << fraction.denum();
}

int main() {
        fraction f1{1,2};
        cout << "f1 :" << f1 << endl;
        fraction f2{f1};
        cout << "f2: " << f2 << endl;
        f2.denum(3);
        cout << "f2: " << f2 << endl;
        cout << "f1: " << f1 << endl;
}


/**
 * Aufgabe:
 *
 * ’Ravencastle’
Eine Klasse ’bruch’ (’fraction’) entwerfen.
• Implementieren Sie einen default-ctor und einen dtor.
• Implementieren Sie einen ctor, der Zähler und Nenner übergeben bekommt. Nutzen
Sie ’:’ zur Initialisierung.
• Implementieren Sie ’getter’ und ’setter’ für (ganzzahlige) Zähler bzw. Nenner.
• Schreiben Sie aussagekräftigen Testcode.
Erweiterung:
• Implementieren Sie einen copy-ctor.
• Implementieren Sie einen operator ’«’ zur Ausgabe.
• Verwenden Sie so oft wie möglich ’const’.
 */
