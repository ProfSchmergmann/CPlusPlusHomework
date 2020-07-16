//
// Created by Sven on 27.05.2020.
//
/**
 * ’Rose Pond’
    new, dynamischen Strukturen, smart pointer
    • Legen Sie eine Struktur ’address’ an, die einen Namen und eine Tel.Nr., beides vom
        Typ ’string’, enthält.
    • Speichern Sie drei fiktive Datensätze jeweils unter einer ID in einer
        ’unordered_map<int,address*>’. Die ’address’-Struktur erhalten Sie dynamisch mit
        ’new’ und speichern nur den Zeiger.
    • Geben Sie die komplette Map aus.
    Erweiterung:
    • Geben Sie die Daten der Map am Ende wieder frei. Testen Sie Ihren Code auf
        Speicherlecks.
    • Verwenden Sie ’unique_ptr’ statt ’address*’.
 */

#include <iostream>
#include <unordered_map>
#include <memory>

using namespace std;

struct adress {
    string name;
    string number;

    adress(string name, string number) : name(name), number(number) {

    }
};

int main() {
    auto *a = new adress{"Max Mustermann", "123 456 789"};
    auto *b = new adress{"Michael Mustermann", "456 789 123"};
    auto *c = new adress{"Frauke Musterfrau", "789 123 456"};

    unordered_map<int, adress *> unorderedMap{
            {1, a},
            {2, b},
            {3, c}
    };

    for (auto x : unorderedMap) {
        cout << x.first << " : " << x.second->name << " , " << x.second->number << endl;
    }

    for (auto x : unorderedMap) {
        delete x.second;
    }

    unorderedMap.clear();

    cout << endl;

    auto *p1 = new adress("Max Mustermann", "123 456 789");
    auto *p2 = new adress("Michael Mustermann", "456 789 123");
    auto *p3 = new adress("Frauke Musterfrau", "789 123 456");

    unordered_map<int, unique_ptr<adress>> unorderedMap2{};
    unorderedMap2.insert(make_pair(0, unique_ptr<adress>(p1)));
    unorderedMap2.insert(make_pair(1, unique_ptr<adress>(p2)));
    unorderedMap2.insert(make_pair(2, unique_ptr<adress>(p3)));

    for (auto it = unorderedMap2.begin(); it != unorderedMap2.end(); it++) {
        cout << it->first << " : " << it->second->name << " , " << it->second->number << endl;
    }

    delete p1;
    delete p2;
    delete p3;

}