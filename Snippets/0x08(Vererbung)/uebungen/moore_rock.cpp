//
// Created by Sven on 05.06.2020.
//

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class window {
private:
    int id;
public:
    void show() {
        cout << "window::show()" << endl;
    }

    void hide() {
        cout << "window::hide()" << endl;
    }

    virtual void draw() {}
};

class button : public window {
    void draw() override {
        cout << "button::draw" << endl;
    }
};

class checkbox : public window {
    void draw() override {
        cout << "checkbox::draw" << endl;
    }
};

int main() {

    vector<unique_ptr<window>> vector1;
    vector1.push_back(make_unique<button>());
    vector1.push_back(make_unique<checkbox>());


    for (const auto& x : vector1) {
        x->draw();
    }

}
