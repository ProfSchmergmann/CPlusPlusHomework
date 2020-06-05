//
// Created by Sven on 29.05.2020.
//
/**
 * ’Deerwoods’
    Operatoren
    • Implementieren Sie eine generische Klasse ’nullable’, die einen mathematischen Wert
        modelliert, der auch ’null’ sein kann.
    • Nutzen Sie intern ein Attribut vom Datentyp, der durch den Template-Parameter
        bestimmt wird, sowie einen ’bool’, welcher angibt, ob der Wert ’null’ ist oder nicht.
    • Grundsätzlich soll addiert werden können. Natürlich kann man auch auf ’null’ testen
        und den Wert ’null’ setzen.
    • Implementieren Sie geeignete Operatoren bzw. Funktionen, so dass folgende
        Codeschnipsel für eine ’nullable’-Instanz ’n’, bzw. ’n1’ und ’n2’, funktionieren:
    • ’n=1;’ setzt einen Wert, hier 1.
    • ’n.reset();’ bedeutet, ’n’ auf ’null’ zu setzen.
    • ’n+=3;’ addiert einen Wert zu ’n’, hier 3.
    • ’n1+n2’ addiert ’n1’ und ’n2’.
    • ’!n’ testet auf ’null’ und ist wahr, wenn nicht.
    • ’(int)n;’ wandelt in den konkreten Datentyp um, hier ’int’ .
    • ’cout « n;’ gibt den Wert von ’n’ aus.
        Testen Sie Ihren Code aussagekräftig.
 */

#include <iostream>

using namespace std;

template<typename T>
class nullable {
public:
    typedef T value_type;
private:
    value_type m_value;
    bool isNull = true;

public:

    void operator=(value_type value) {
        isNull = false;
        m_value = value;
    }

    void reset() {
        isNull = true;
        m_value = nullptr;
    }

    void operator+=(value_type value) {
        if (isNull) {
            *this = value;
        } else {
            try {
                m_value += value;
            } catch (...) {
                return;
            }
        }
    }

    bool operator!() const {
        return isNull;
    }

    value_type operator()

    nullable(const nullable& n) {
        nullable m;
        m = n.m_value;
        return m;
    }

    friend nullable operator+(const nullable& n1, const nullable& n2) {
        nullable n(n1);
        return n += n2;
    }
};

int main() {
    nullable<int> n{};
}
