//
// Created by Sven on 08.05.2020.
//

/**
 * Klasse zu Template erweitern.
    • Erweitern Sie die Klasse ’punkt’ aus Übung ’Stone Ridge’ zu einem Template.
    • Testen Sie Ihre generische Klasse mit unterschiedlichen Datentypen.
 */


#include <iostream>

using namespace std;

template<typename X, typename Y>
class punkt {
    X m_x;
    Y m_y;

public:
    punkt() : m_x{}, m_y{} {};

    void x(const X &x) {
        m_x = x;
    }

    void y(const Y &y) {
        m_y = y;
    }

    [[nodiscard]] X x() const {
        return m_x;
    }

    [[nodiscard]] Y y() const {
        return m_y;
    }

    punkt(const X &x, const Y &y) : m_x{x}, m_y{y} {
    }

    punkt(const punkt &punkt) : m_x{punkt.x()}, m_y{punkt.y()} {
    }

    ~punkt() = default;

};

template<typename X, typename Y>
ostream &operator<<(ostream &os, const punkt<X,Y> &punkt) {
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

    punkt p3{1.5, 1.5};
    punkt p4{p3};

    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;

    p3.x(100);
    p4.y(10);

    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
}