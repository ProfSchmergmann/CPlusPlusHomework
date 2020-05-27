//
// Created by Sven on 27.05.2020.
//
/**
 * ’Kenford’
    new, dynamischen Strukturen, smart pointer
    • Realisieren Sie eine verkettete Liste, in der jeder Knoten einen ’int’ und einen Zeiger
        (’unique_ptr’) auf den nächsten Knoten enthält. Die Liste enthält einen Zeiger ’root’
        auf den ersten Knoten, sowie einen Zähler ’count’.
    • Die Liste bietet eine Funktion ’add(int n)’ zum Hinzufügen eines Knotens, eine
        Funktion ’clear’ zum Löschen bzw. Freigeben aller Daten sowie einen
    Ausgabeoperator.
    Erweiterung:
    • Testen Sie Ihren Code auf Speicherlecks.
    • Machen sie aus der Liste ein Template für beliebige Datentypen (nicht nur ’int’).
 */

#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct node{
    T value;
    unique_ptr<node> next;

    node<T>(T value) : value(value), next(nullptr) {
    }
};

template<typename T>
class linkedList{
    unique_ptr<node<T>> root;
    size_t count;

public:
    linkedList() : root(nullptr), count(0) {

    }

    void add(T value) {
        unique_ptr<node<T>> temp = make_unique<new node<T>(value)>;
        temp.value = value;
        temp.next = root;
        root = temp;
        count++;
    }

    void clear() {
        while (root != nullptr) {
            auto temp = root;
            root = root.next;
            delete temp;
        }
    }

    ~linkedList() {
        this->clear();
    }

    friend ostream &operator<<(ostream &os, const linkedList &list) {
        os << "[";
        auto temp = list.root;
        while (temp != nullptr) {
            os << temp.value << ", ";
            temp = temp.next;
        }
        os << " ] (" << list.count() << ")";
        return os;
    }

};

int main() {
    linkedList<int> linkedList;
    linkedList.add(1);
    linkedList.add(2);
    linkedList.add(3);
    cout << linkedList << endl;
    linkedList.clear();
    cout << linkedList << endl;
}

