//
// Created by Sven on 29.05.2020.
//
/**
 * ’Dover Town’
    Operatoren
    • Implementieren Sie eine Klasse ’states’, die eine Menge von Zuständen enthalten
        kann, wovon genau einer aktiv ist. Beispiele von Zuständen: { ’Locked’, ’Unlocked’ }
        oder auch { ’Connected’, ’Disconnected’, ’Unknown’ }.
    • Nutzen Sie intern einen ’vector’ von ’string’ zum Speichern der States, und einen
        Index für den gerade aktuellen Zustand.
    • Grundsätzlich soll ein bestimmter Zustand abgefragt und gesetzt werden können.
        Weiter kann man den aktuellen Zustand um eins weiter oder um eins zurück setzen.
        Natürlich sollen auch Zustände hinzugefügt werden und alle gelöscht werden
        können.
    • Implementieren Sie geeignete Operatoren bzw. Funktionen, so dass folgende
        Codeschnipsel für eine ’states’-Instanz ’s’ funktionieren:
    • ’s+=“home”’ fügt Zustand ’home’ zu ’s’ hinzu.
    • ’s=1;’ setzt aktuellen Zustand auf den zweiten Zustand.
    • ’++s;’ setzt den aktuellen Zustand um eins weiter.
    • ’-–s;’ setzt den aktuellen Zustand um eins zurück.
        Beim Über- oder Unterlauf vorne bzw. hinten anfangen.
    • ’s[s()]’ gibt den aktuellen Zustand (string) zurück.
    • ’s.clear();’ löscht alle Zustände.
    • ’cout « s;’ gibt einen Vektor mit allen Zuständen aus.
    Testen Sie Ihren Code aussagekräftig.
 */

#include <iostream>
#include <vector>

using namespace std;

class states {
    vector<string> m_states;
    int state;

public:

    /**
     * Constructor which sets the member vector and the initial state.
     */
    states() {
        m_states.emplace_back("Connected");
        m_states.emplace_back("Disconnected");
        m_states.emplace_back("Unknown");
        state = 2;
    }

    void operator+=(string s) {
        m_states.push_back(s);
    }


    void operator=(int i) {
        state += i;
        if (state >= m_states.size() - 1) {
            state = state % m_states.size();
        }
    }

    void operator++() {
        *this = 1;
    }

    void operator--() {
        *this = -1;
    }

    /**
     * Operator [] which returns the state at the specific index.
     * @param i the index
     * @return a string
     */
    const string &operator[](int i) const {
        if (i > -1 && i < m_states.size()) {
            return m_states[i];
        } else {
            throw "No such index found!";
        }
    }

    /**
     * Operator () which returns the current state.
     * @return an int
     */
    int operator()() const {
        return state;
    }

    /**
     * Method for deleting the states in the member vector.
     * This method also sets the state to -1.
     */
    void clear() {
        if (m_states.empty()) {
            return;
        } else {
            m_states.clear();
            state = -1;
        }
    }

    /**
     * Method for returning the size.
     * @return size_t object
     */
    size_t size() const {
        if (state == -1) {
            return 0;
        }
        return m_states.size();
    }


};

ostream &operator<<(ostream &os, const states &s) {
    os << "[";
    for (int i = 0; i < s.size(); ++i) {
        os << s[i];
        if (i != s.size() - 1) {
            os << " , ";
        }
    }
    os << "]";
}

int main() {
    states s;
    cout << s << endl;
    cout << "-----" << endl;
    s += "home";
    cout << s << endl;
    cout << "-----" << endl;
    s = 1;
    cout << s[s()] << endl;
    cout << "-----" << endl;
    ++s;
    cout << s[s()] << endl;
    cout << "-----" << endl;
    --s;
    cout << s[s()] << endl;
    cout << "-----" << endl;
    s.clear();
    cout << s << endl;
    cout << "-----" << endl;

}
