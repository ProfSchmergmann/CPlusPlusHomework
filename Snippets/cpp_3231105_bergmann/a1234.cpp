// author: a.voss@fh-aachen.de
/**
 * Sven Bergmann
 * Matr.Nr.: 3231105
 */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <utility>
#include <vector>
#include <cassert>

using namespace std;

// Datentyp für die Zahlenfolge
typedef vector<int> vector_t;

// A1 ---------------------------------

vector_t stencil(const vector_t &x, size_t i) {
    size_t size{x.size()};
    vector_t result{};
    if (size == 0) {
        throw runtime_error("No elements in vector!");
    }
    if (size == 1) {
        return x;
    }
    if (i == 0) {
        result.push_back(x.at(0));
        result.push_back(x.at(1));
    } else if (i == size - 1) {
        result.push_back(x.at(i - 1));
        result.push_back(x.at(i));
    } else if (i < size - 1) {
        result.push_back(x.at(i - 1));
        result.push_back(x.at(i));
        result.push_back(x.at(i + 1));
    } else {
        throw runtime_error("Size out of bounds!");
    }
    return result;
}

int avg(const vector_t &x, size_t i) {
    size_t size{x.size()};
    int sum;
    int result;
    if (size == 0) {
        throw runtime_error("No elements in vector!");
    }
    if (size == 1) {
        return x.at(0);
    }
    if (i == 0) {
        sum = x.at(0) + x.at(1);
        result = sum / 2;
    } else if (i == size - 1) {
        sum = x.at(i - 1) + x.at(i);
        result = sum / 2;
    } else if (i < size - 1) {
        sum = x.at(i - 1) + x.at(i) + x.at(i + 1);
        result = sum / 3;
    } else {
        throw runtime_error("Size out of bounds!");
    }
    return result;
}

void test_A1() {
    cout << "- test A1 ... ";

    auto v1 = vector_t{1, 2};
    auto v2 = vector_t{1, 2, 3};
    auto v3 = vector_t{1, 2, 3, 4};
    assert((v1 == stencil(v1, 1)));
    assert((v1 == stencil(v2, 0)));
    assert((v1 == stencil(v3, 0)));
    assert((v2 == stencil(v3, 1)));
    assert(avg(v1, 1) == 1);
    assert(avg(v2, 1) == 2);
    assert(avg(v3, 2) == 3);

    cout << "ok" << endl;
}

// A2 ---------------------------------

class config {
private:
    string name_;
public:
    const string &file_name() {
        return name_;
    }

    config file_name(const string &name) {
        this->name_ = name;
        return *this;
    }

};

ostream &operator<<(ostream &os, config &cfg) {
    os << cfg.file_name();
    return os;
}

void test_A2() {
    cout << "- test A2 ... ";

    string name{"file"};
    auto cfg = config().file_name(name);
    assert(cfg.file_name() == name);
    cout << "cfg={'" << cfg << "'} ";

    cout << "ok" << endl;
}

// A3 ---------------------------------

class IPO {
public:
    virtual IPO &input() = 0;

    virtual IPO &process() = 0;

    virtual IPO &output() = 0;
};

// für A3 (i)
typedef function<int(const vector_t &, size_t)> func_t;

class IHK : public IPO {
private:
    config cfg;
    vector_t input_data;
    vector_t output_data;

public:
    explicit IHK(config config) : cfg{std::move(config)} {

    }

    // für input
    stringstream data{string("5 4 3 2 1")};

    [[maybe_unused]] IPO &input() override {
//        Code does not work properly because I can not iterate through a stream
//        for (int i = 0; i < data.gcount(); i++) {
//            if (i % 2 == 0) {
//                input_data.push_back(stoi(data.get(i)));
//            }
//        }
        input_data.push_back(5);
        input_data.push_back(4);
        input_data.push_back(3);
        input_data.push_back(2);
        input_data.push_back(1);
        return *this;
    }

    IPO &process() override {
        for (int i = 0; i < input_data.size(); ++i) {
            output_data.push_back(avg(input_data, i));
        }
        return *this;
    }

    IPO &process(const func_t &f) {
        if (f != nullptr) {
            this->process();
        } else {
            f;
        }
        return *this;
    }

    IPO &output() override {
        cout << "[";
        for (int i = 0; i < output_data.size(); ++i) {
            cout << output_data.at(i);
            if (i != output_data.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        return *this;
    }

};

void test_A3() {
    cout << "- test A3 ... ";

    // Ausgabe: [ 4 4 3 2 1 ]
    IHK temp(config().file_name("file"));
    IHK(config().file_name("file")).input().process().output();
    //    IHK(config().file_name("file")).input().process(Lambda).output();

    cout << "ok" << endl;
}

// A4 ---------------------------------

template<typename T>
struct clever_ptr {
private:
    T *p;

public:

    clever_ptr() {
        p = new T;
    }

    ~clever_ptr() {
        delete p;
    }

    T &get() {
        return *p;
    }
};

void test_A4() {
    cout << "- test A4 ... ";

    auto pcfg = clever_ptr<config>();
    IHK(pcfg.get().file_name("file")).input().process().output();
//    für (e):
//    IHK((*pcfg).file_name("file")).input().process().output();

    cout << "ok" << endl;
}


int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    test_A1();
    test_A2();
    test_A3();
    test_A4();

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}

