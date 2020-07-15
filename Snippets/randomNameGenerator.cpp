//
// Created by sberg on 15.07.2020.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>

using namespace std;

vector<string> firstNames;
vector<string> lastNames;

vector<string> readFile(const string &file_in);

string combineRandomly(const vector<string> &vector1,
                       const vector<string> &vector2);

int main() {

    firstNames = readFile("../Vorname.txt");
    lastNames = readFile("../Nachname.txt");

    cout << combineRandomly(firstNames, lastNames) << endl;

}

vector<string> readFile(const string &file_in) {

    vector<string> names;

    ifstream ifstream1(file_in);
    if (ifstream1.is_open()) {
        string line;
        while (getline(ifstream1, line)) {
            names.push_back(line);
        }
    }
    ifstream1.close();

    return names;
}

string combineRandomly(const vector<string> &vector1,
                       const vector<string> &vector2) {

    random_device rd1;
    uniform_int_distribution<> distr(0, vector1.size() - 1);
    int random1{distr(rd1)};

    random_device rd2;
    uniform_int_distribution<> distr2(0, vector2.size() - 1);
    int random2{distr(rd2)};

    string result = vector1[random1] + " " + vector2[random2];
    return result;
}