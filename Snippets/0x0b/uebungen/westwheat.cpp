//
// Created by Sven on 26.06.2020.
//

/**
 * ’Westwheat’
    Threads, Mutex, ref
        Starten Sie zwei Threads und füllen Sie in der Workerfunktion einen (globalen) intvector
        jeweils mit n Zufallszahlen.
    • Starten Sie mit kleinem n (<5) und schützen Sie den Zugriff auf den Vektor nicht.
        Funktioniert das?
    • Erhöhen Sie nun die Anzahl n solange, bis das Programm abstürzt. Warum ist das so?
    • Schützen Sie den Vektor beim Einfügen mit einem lock_guard (thread-safe).
        Funktioniert es jetzt wieder?
    • Anstatt den Vektor global zu definieren, definieren Sie ihn lokal und übergeben Sie
        ihn als Referenz der Workerfunktion.
 */

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

vector<int> vector1;
mutex mutex_vector1;

void work(int n) {
    for (int i = 0; i < n; ++i) {
        lock_guard<mutex> lk(mutex_vector1);
        vector1.push_back(rand());
    }
}

void work2(int n, vector<int>& vector2);

int main() {

    int length{5};
    thread t1(work, length);
    thread t2(work, length);
    t1.join();
    t2.join();
    for (int i = 0; i < length; ++i) {
        cout << vector1.at(i) << endl;
    }

    vector<int> vector2;
    thread t3(work2, length, std::ref(vector2));
    thread t4(work2, length, std::ref(vector2));
    t3.join();
    t4.join();
    for (int i = 0; i < length; ++i) {
        cout << vector2.at(i) << endl;
    }

}

void work2(int n, vector<int>& vector2) {
    mutex mutex_vector2;
    for (int i = 0; i < n; ++i) {
        lock_guard<mutex> lk(mutex_vector2);
        vector2.push_back(rand());
    }
}