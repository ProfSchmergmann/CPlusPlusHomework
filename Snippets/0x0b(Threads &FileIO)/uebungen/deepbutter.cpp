//
// Created by Sven on 26.06.2020.
//

/**
 * ’Deepbutter’
    Mutex, lock, unlock, unique_lock
    • Starten Sie zwei Threads in main und lassen Sie sie sicher (!) in einen Wartezustand
        laufen.
    • Signalisieren Sie aus main heraus dem ersten Thread, dass er weiterlaufen kann und
        warten auf das Ende der beiden Threads.
    • Nach Erhalt des Signals im ersten Thread signalisieren dem zweiten Thread, dass er
        nun weiterlaufen kann.
    • Die beiden Threads haben keine besonderen Aufgaben, es geht hier lediglich um eine
        wohldefinierte Reihenfolge der Abarbeitung. Verwenden Sie kein sleep, sondern
        lösen Sie das Problem durch die richtige Verwendung der Befehle.
 */

#include <iostream>
#include <thread>
#include <condition_variable>

using namespace std;

void work1() {
    cout << "Thread t1 starts" << endl;

}

int main() {
    condition_variable cv;
    thread t1
}