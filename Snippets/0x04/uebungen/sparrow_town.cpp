//
// Created by Sven on 08.05.2020.
//

/**
 * Klasse zu Template erweitern.
    • Erweitern Sie die Klasse ’bruch’ bzw. ’fraction’ aus Übung ’Ravencastle’ zu einem
        Template.
    • Testen Sie Ihre generische Klasse mit unterschiedlichen Datentypen.
 */

#include <iostream>

using namespace std;

template<typename T1, typename T2>
class fraction {
    T1 m_num;
    T2 m_denum;

public:

    // Default Konstruktor, siehe Aufgabenstellung
    fraction() : m_num{}, m_denum{} {};

    // Konstruktor, welcher beide Variablen setzt
    fraction(const T1 &num, const T2 &denum) : m_num{num}, m_denum{denum} {
    }

    // Getter fuer das Attribut m_num
    [[nodiscard]] T1 num() const {
        return m_num;
    }

    // Setter fuer das Attribut m_num
    void num(const T1 &num) {
        m_num = num;
    }

    // Getter fuer das Attribut m_denum
    [[nodiscard]] T2 denum() const {
        return m_denum;
    }

    // Setter fuer das Attribut m_denum
    void denum(const T2 &denum) {
        m_denum = denum;
    }

    // Copy - Konstruktor
    fraction(const fraction &fraction) : m_num{fraction.num()}, m_denum{fraction.denum()} {
    }

    // Default Destructor, siehe Aufgabenstellung
    ~fraction() = default;

};

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const fraction<T1, T2> &fraction) {
    os << fraction.num() << "/" << fraction.denum();
}

int main() {
    fraction f1{1., 2.};
    cout << "f1 :" << f1 << endl;
    fraction f2{f1};
    cout << "f2: " << f2 << endl;
    f2.denum(3);
    cout << "f2: " << f2 << endl;
    cout << "f1: " << f1 << endl;
}
