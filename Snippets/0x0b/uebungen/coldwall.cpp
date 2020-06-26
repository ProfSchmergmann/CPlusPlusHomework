//
// Created by Sven on 26.06.2020.
//

/**
 * ’Coldwall’
    Threads, Mutex, ref
    • Überlegen Sie sich eine geeignete parallele Strategie mit mehreren Threads und
        summieren Sie die Zahlen 1..n parallel und thread-safe in einer gemeinsamen lokalen
        Summenvariablen auf.
    • Messen Sie die Zeit jeweils für keine Parallelisierung, für zwei Threads, drei Threads
        usw. Ab wie vielen Threads wird es nicht mehr schneller bzw. wird es überhaupt
        schneller?
 */

#include <iostream>

using namespace std;
