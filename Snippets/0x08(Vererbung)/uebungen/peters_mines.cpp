//
// Created by Sven on 05.06.2020.
//

#include <iostream>
using namespace std;

class befoerderungsmittel {
public:
    int m_sitzplaetze;

    befoerderungsmittel(int sitzplaetze) : m_sitzplaetze{sitzplaetze} {
        cout << "befoerderungsmittel::ctor()" << endl;
    }

    virtual ~befoerderungsmittel(){
        cout << "befoerderungsmittel::dtor()" << endl;
    }
};

class fahrzeug {
public:
    double m_hoechstgeschwindigkeit;

    fahrzeug(double hoechstgeschwindigkeit) : m_hoechstgeschwindigkeit{hoechstgeschwindigkeit} {
        cout << "fahrzeug::ctor()" << endl;
    }

    ~fahrzeug(){
        cout << "fahrzeug::dtor()" << endl;
    }
};

class automobile : public fahrzeug, virtual public befoerderungsmittel {

public:
    automobile(int sitzplaetze, double hoechstgeschwindigkeit) :
    fahrzeug(hoechstgeschwindigkeit), befoerderungsmittel(sitzplaetze) {
        cout << "automobile::ctor()" << endl;
    }

    ~automobile() override{
            cout << "automobile::dtor()" << endl;
        }
};

class boot : public fahrzeug, virtual public befoerderungsmittel {

public:
    boot(int sitzplaetze, double hoechstgeschwindigkeit) :
            fahrzeug(hoechstgeschwindigkeit), befoerderungsmittel(sitzplaetze) {
        cout << "boot::ctor()" << endl;
    }

    ~boot() override {
        cout << "boot::dtor()" << endl;
    }
};

class amphibie : public boot, public automobile {
public:
    amphibie(int sitzplaetze, double hoechstgeschwindigkeitLand, double hoechstgeschwindigkeitWasser)
            :
            befoerderungsmittel(sitzplaetze), automobile(sitzplaetze, hoechstgeschwindigkeitLand),
            boot(sitzplaetze, hoechstgeschwindigkeitWasser) {
    }
    ~amphibie() override {
        cout << "amphibie::dtor()" << endl;
    }
};

int main() {

    amphibie a{4, 120, 15};
    cout << "-----" << endl;
    cout << "Sitzplaetze von a: " << a.m_sitzplaetze << endl;
    cout << "Höchstgeschwindigkeit im Wasser von a: " << a.boot::m_hoechstgeschwindigkeit << endl;
    cout << "Höchstgeschwindigkeit an Land von a: " << a.automobile::m_hoechstgeschwindigkeit << endl;

}
