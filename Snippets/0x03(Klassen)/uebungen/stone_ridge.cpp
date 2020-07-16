//
// Created by Sven on 24.04.2020.
//

#include <iostream>

using namespace std;

class punkt {
    double m_x;
    double m_y;

public:
    punkt() : m_x{}, m_y{} {};

    void x(const double &x) {
        m_x = x;
    }

    void y(const double &y) {
        m_y = y;
    }

    [[nodiscard]] double x() const {
        return m_x;
    }

    [[nodiscard]] double y() const {
        return m_y;
    }

    punkt(const double &x, const double &y) : m_x{x}, m_y{y} {
    }

    punkt(const punkt &punkt) : m_x{punkt.x()}, m_y{punkt.y()} {
    }

    ~punkt() = default;

};

ostream &operator<<(ostream &os, const punkt &punkt) {
    os << "x = " << punkt.x() << ", y = " << punkt.y();
    return os;
}

int main() {
    punkt p1{1, 1};
    punkt p2{p1};

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    p1.x(100);
    p2.y(10);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

}



/**
 * ’Stone Ridge’
Eine Klasse ’punkt’ mit ’x’- und ’y’-Koordinate entwerfen.
• Implementieren Sie einen default-ctor und einen dtor.
• Implementieren Sie einen weiteren ctor, der einen x- und einen y-Wert vom Typ
’double’ übergeben bekommt. Benutzen Sie ’:’ zur Initialisierung.
• Implementieren Sie ’getter’ und ’setter’ für ’x’ und ’y’.
• Schreiben Sie aussagekräftigen Testcode.
Erweiterung:
• Implementieren Sie einen copy-ctor.
• Implementieren Sie einen operator ’«’ zur Ausgabe.
• Verwenden Sie so oft wie möglich ’const’.
 */
