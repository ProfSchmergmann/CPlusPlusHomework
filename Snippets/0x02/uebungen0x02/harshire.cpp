//
// Created by sberg on 17.04.2020.
//

#include <iostream>
#include <array>

using namespace std;

const int dim = 3;

struct stack_exception {
    string what;
    char level;
};

struct stack {
    array<int, dim> arr;
    int next = 0;

    void push(int p) {
        if (next >= 0 && next < 3) {
            arr.at(next) = p;
            next++;
        } else {
            throw stack_exception{"Stack is full", 'F'};
        }
    }

    //Returns the last stacked element and
    // sets the pointer at this element to be overwritten.
    int pop() {
        if (next > 0 && next < 4) {
            next--;
            return arr.at(next);
        } else {
            throw stack_exception{"Stack is empty", 'E'};
        }
    }
};

int main() {
    stack s;
    try {
        s.push(1);
    } catch (const stack_exception& e) {
        cerr << e.what << endl;
    }
    cout << "Stack after push: " << s.arr.at(0) << endl;
    try {
        s.pop();
    } catch (const stack_exception& e) {
        cerr << e.what << endl;
    }
    cout << "Stack after pop: " << s.arr.at(0) << endl;
    try {
        s.pop();
    } catch (const stack_exception& e) {
        cerr << e.what << endl;
    }
}