//
// Created by Sven on 24.04.2020.
//

#include <iostream>

using namespace std;


const int dim{3};

class polynom {
    double m_coeffs[dim]{};

public:
    polynom() = default;

    [[nodiscard]] double x0() const {
        return m_coeffs[0];
    }

    [[nodiscard]] double x1() const {
        return m_coeffs[1];
    }

    [[nodiscard]] double x2() const {
        return m_coeffs[2];
    }

    void x0(const double x0) {
        m_coeffs[0] = x0;
    }

    void x1(const double x1) {
        m_coeffs[1] = x1;
    }

    void x2(const double x2) {
        m_coeffs[2] = x2;
    }

    polynom(const double x0, const double x1, const double x2) {
        this->x0(x0);
        this->x1(x1);
        this->x2(x2);
    }

    double eval(double x) {
        return (this->x0() + (this->x1() * x) + (this->x2()) * x * x);
    }

    double at(int index) {
        return (index >= 0 && index < dim) ? m_coeffs[index] : throw runtime_error("Index is not in range!");
    }

    polynom add(const polynom& p2) {
        return polynom(this->x0() + p2.x0(), this->x1() + p2.x1(), this->x2() + p2.x2());
    }

    ~polynom() = default;
};


ostream &operator<<(ostream &os, polynom polynom) {
    os << polynom.x0() << " + " << polynom.x1() << "x + " << polynom.x2() << "x^2";
    return os;
}

int main() {
    polynom p1{1, 2, 3};
    polynom p2{0,0,1};

    cout << "p1 : f(x) = " << p1 << endl;
    cout << "p1 : f(2) = " << p1.eval(2) << endl;
    cout << "p2 : f(x) = " << p2 << endl;
    cout << "p2 : f(2) = " << p2.eval(2) << endl;
    cout << "p1 + p2 : f(x) = " << p1.add(p2) << endl;


    try {
        p1.at(4);
    } catch (runtime_error &e) {
        cout << "Error" << endl;
    }
}


/**
 * ’Meadow River’
• Überführen Sie die Struktur ’polynom’ aus Übung ’Elkford’ in eine Klasse ’polynom’.
• Überführen Sie die Funktion ’eval’ in eine Memberfunktion.
• Implementieren Sie eine Memberfunktion ’at’, die einen Index ’i’ übergeben bekommt
und den i’ten Koeffizienten zurückgibt. Werfen Sie eine Ausnahme, falls ’i’ ungültig
ist.
Erweiterung:
• Implementieren Sie eine globale Funktion ’add’, um zwei Polynome zu addieren und
geben Sie das Ergebnis zurück.
• Nutzen Sie Ihren Testcode aus ’Elkford’ und testen Sie zusätzlich mit der
Dimension 4.
 */
