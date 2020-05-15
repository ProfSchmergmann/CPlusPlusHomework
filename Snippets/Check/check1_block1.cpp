// author: a.voss@fh-aachen.de

// Ihr Name: Sven Bergmann
// Matr.nr.: 3231105

/**************************************
 *                                    *
 * Name und Matr.nr. oben eintragen!  *
 *                                    *
 * Die Teilaufgaben stehen am Ende!   *
 *                                    *
 * Ergänzen Sie bzw. kommentieren Sie *
 * den Code entsprechend ein!         *
 *                                    *
 **************************************/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::unordered_map;
using std::initializer_list;
using std::vector;
using std::runtime_error;

// a) Typen definieren: index_type, value_type, vector_type

typedef unsigned int index_type;
typedef string value_type;
typedef vector<string> vector_type;

// b) globale Var. next_id

index_type next_id{100};

// c) globale Fkt. make_id

index_type make_id() {
    return next_id++;
}

class multi_set {

// d) öffentliche Member map und max_keys

public:
    unordered_map<index_type, vector_type> m_map;
    unsigned int m_max_keys;

// e) ctor mit max_keys

multi_set(unsigned int max_keys) : m_max_keys{max_keys} {

};

// f) Memberfunktion add mit ID und initializer_list

/**
 * Definieren Sie eine Funktion add, die als ersten Parameter eine ID vom
 *      Typ index_type und als zweiten Parameter eine initializer_list von string
 *      bekommt.
 *      Diese Funktion soll unter dieser ID in der Membervariablen map die Liste
 *      von Strings hinzufügen (als Vektor) bzw. wenn unter der ID schon ein Vektor
 *      existiert, diesen um die übergebenen strings erweitern. Vergleichen Sie
 *      den entsprechenden Output in main um zu sehen, was passiert.
 *      Falls die Anzahl der IDs in der map größer oder gleich dem max_keys
 *      Wert ist, werfen Sie einen runtime_error und fügen keine Daten hinzu.
 *      add gibt die ID zurück.
 *      Nutzen sie auto& und range-based-for, um über die Liste zu iterieren.
 */

index_type add(const index_type &id, const string initializer_list[]) {
        if (m_map.find(id) != m_map.end()) {
            auto it = m_map.find(id)->second.end();
            for (int i = 0; i < initializer_list->size(); ++i) {
                m_map.find(id)->second.insert(i,initializer_list[i]);
            }
        }

    return id;
}

// g) Memberfunktion add mit ID make_id()

void add(const string initializer_list[]) {
    this->add(make_id(), initializer_list);
}

// h) Memberfunktion get um map abzufragen

const vector_type get(index_type id) {
    return m_map.find(id)->second;
}

// i) Memberfunktion size um Anzahl IDs abzufragen

const unsigned int &size() {
    int temp{0};
    for(auto x : m_map) {
        temp++;
    }
    return temp;
}

};

// j) Beispieloperator

ostream& operator<<(ostream& os, const vector_type& v) {
    bool first{true};

    os << "[";
    for (auto& x:v) {
        if (first)
            first=false;
        else
            os << ",";
        os << "'" << x << "'";
    }
    os << "]";
    return os;
}

// k) Operator für multi_set

ostream& operator<<(ostream& os, const multi_set& s) {
    int size = s.size();
    for(int i=0; i<size +1; i++) {

    }
    return os;
}


int main()
{
    cout << endl << "--- " << __FILE__ << " ---" << endl
         << endl;

//    multi_set set(2);
//    index_type id100,id100a,id101;

//    cout << "01|    |set|=" << set.size() << ", set:" << set << endl;

//    id100 = set.add({"Hello"});
//    cout << "02|    |set|=" << set.size() << ", set:" << set << ", id100:" << id100 << endl;

//    id100a = set.add(id100,{"World","!"});
//    cout << "03|    |set|=" << set.size() << ", set:" << set << ", id100a:" << id100a << endl;

//    id101 = set.add({"a","b"});
//    cout << "04|    |set|=" << set.size() << ", set:" << set << ", id101:" << id101 << endl;

// Ausgabe bis hierher:
// 01|    |set|=0, set:{}
// 02|    |set|=1, set:{(100,['Hello'])}, id100:100
// 03|    |set|=1, set:{(100,['Hello','World','!'])}, id100a:100
// 04|    |set|=2, set:{(101,['a','b']),(100,['Hello','World','!'])}, id101:101

    cout << "-----" << endl;

//    auto v100 = set.get(id100);
//    cout << "05|    |v100|=" << v100.size() << endl;

//    auto v101 = set.get(id101);
//    cout << "06|    |v101|=" << v101.size() << endl;

//    auto v102 = set.get(id101+1);
//    cout << "07|    |v102|=" << v102.size() << endl;

// Ausgabe bis hierher:
// 05|    |v100|=3
// 06|    |v101|=2
// 07|    |v102|=0

    cout << "-----" << endl;

    try {
//        set.add({"oops"});
    } catch (const runtime_error& e) {
        cout << "08|    error: " << e.what() << endl;
    }

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

/*
 * Es soll ein Container entworfen werden, der eine Menge von Strings (vector)
 * jeweils zu einer ID (einer Nummer) verwaltet, d.h. wir reden von einer Klasse,
 * die eine entsprechende unordered_map als Member enthält.
 *
 * Auszugsweise soll implementiert werden, dass Mengen zu einer ID hinzugefügt
 * oder abgefragt werden können, solange eine maximale Anzahl von IDs nicht
 * überschritten wurde.
 *
 * Die folgenden Teilaufgaben können der Reihe nach umgesetzt werden. Wenn Sie
 * an einer Stelle nicht weiter wissen, überlegen Sie sich eine Alternative.
 * Zum Teil sind Alternativen angegeben, so dass Sie die Bearbeitung fortsetzen
 * können.
 *
 * Kommentieren Sie jeweils in main den entsprechenden Code ein und testen Sie
 * Ihren Code.
 *
 * a)   Definieren Sie drei eigene Datentypen:
 *      - index_type ist ein unsigned int,
 *      - value_type ist ein string,
 *      - vector_type ist ein vector von strings
 *      Wenn Sie nicht wissen, wie das geht, verwenden Sie die angegeben Typen
 *      direkt.
 * ->   4 Punkte
 *
 * b)   Definieren Sie eine globale Variable next_id vom index_type und
 *      initialisieren Sie sie mit 100.
 * ->   4 P.
 *
 * c)   Definieren Sie eine globale Funktion make_id, die next_id zurückgibt
 *      und die globale Variable um eins erhöht. Die Funktion ist dafür
 *      zuständig, eine Art eindeutige ID zu generieren. Sie hat keine Parameter.
 * ->   4 P.
 *
 * d)   In der Klasse multi_set definieren Sie zwei öffentliche Membervariablen:
 *      - map vom Typ unordered_map mit den beiden Template-Argumenten index_type
 *        und vector_type
 *      - max_keys vom Typ unsigned int
 *      map kann so zu einem Index, d.h. einer ID, einen Vektor von Strings
 *      assoziieren und max_keys gibt die maximale Anzahl von IDs an, die wir
 *      zulassen wollen.
 * ->   4 P.
 *
 * e)   Definieren Sie einen ctor mit einem unsigned int Parameter max_keys und
 *      initialisieren Sie den Member max_keys damit.
 * ->   4 P.
 *
 * f)   Definieren Sie eine Funktion add, die als ersten Parameter eine ID vom
 *      Typ index_type und als zweiten Parameter eine initializer_list von string
 *      bekommt.
 *      Diese Funktion soll unter dieser ID in der Membervariablen map die Liste
 *      von Strings hinzufügen (als Vektor) bzw. wenn unter der ID schon ein Vektor
 *      existiert, diesen um die übergebenen strings erweitern. Vergleichen Sie
 *      den entsprechenden Output in main um zu sehen, was passiert.
 *      Falls die Anzahl der IDs in der map größer oder gleich dem max_keys
 *      Wert ist, werfen Sie einen runtime_error und fügen keine Daten hinzu.
 *      add gibt die ID zurück.
 *      Nutzen sie auto& und range-based-for, um über die Liste zu iterieren.
 * ->   16 P.
 *
 * g)   Definieren Sie eine zweite Funktion add, die nur die initializer_list
 *      übergeben bekommt und die Funktion add aus f) mit dem ersten Parameter
 *      make_id() aufruft und diese ID somit auch zurückgibt.
 *      Diese Funktion erweitert so zu einer neu generierten ID die map um die
 *      Daten in der Liste, siehe auch main.
 * ->   4 P.
 *
 * h)   Definieren Sie eine Funktion get, die zu einem übergebenen Parameter ID
 *      vom Typ index_type den zugehörigen Vektor in der map findet und als Kopie
 *      zurückgibt, oder einen leeren Vektor zurückgibt.
 *      Nutzen Sie map.find, so dass Sie die Memberfunktion get als const deklarieren
 *      können. Wenn das nicht klappt, nutzen Sie alternativ map[].
 *      Der Rückgabetyp ist natürlich vector_type.
 * ->   12 P.
 *
 * i)   Definieren Sie eine Funktion size(), die die Anzahl von IDs in map zurück
 *      gibt und als const deklariert ist.
 * ->   4 P.
 *
 * j)   Kommentieren Sie den Operator für vector_type ein, wenn Sie den Datentyp
 *      definiert haben. Dieser ist die Vorlage für k).
 * ->   0 P.
 *
 * k)   Definieren Sie analog zu j) einen Ausgabeoperator für multi_set und geben
 *      Sie so aus, wie in main zu sehen, d.h. über alle IDs geben Sie die ID
 *      mit assoziiertem Vektor aus. Nutzen Sie den Operator aus j) und bauen
 *      Sie den Operator analog auf.
 * ->   4 P.
 *
 * Gesamtsumme: 60
 */

