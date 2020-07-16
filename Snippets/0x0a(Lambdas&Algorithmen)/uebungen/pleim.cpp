//
// Created by Sven on 19.06.2020.
//
/**
 * ’Smoothrock’
    file IO
    • Implementieren Sie eine "read_all_lines" Funktion, die eine Textdatei komplett
        einliest und die Zeilen in einem Vektor von Strings zurückgibt.
    • Implementieren Sie analog eine "write_all_lines" Funktion, die einen übergebenen
        Vektor von Strings in eine Textdatei schreibt.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> read_all_lines(const string &file_in);

void write_all_lines(const vector<string> &vector1, const string &name);

ostream &operator<<(ostream &os, const vector<string> &vector1) {
    for (const string& line : vector1) {
        os << line << endl;
    }
    return os;
}

int main() {

    vector<string> vector1{read_all_lines("../test.txt")};
    cout << vector1;
    write_all_lines(vector1, "../test_out");

}

vector<string> read_all_lines(const string &file_in) {

    vector<string> lines;

    ifstream if_file_in(file_in);
    if (if_file_in.is_open()) {
        string line;
        while (getline(if_file_in, line)) {
            lines.push_back(line);
        }
        if_file_in.close();
    } else {
        throw runtime_error("File could not be opened.");
    }
    return lines;
}

void write_all_lines(const vector<string> &vector1, const string &name) {

    string file_out{name + "_out.txt"};
    ofstream ofs_file_out{file_out};
    if (ofs_file_out) {
        for (const string& line: vector1) {
            ofs_file_out << line << endl;
        }
    }
    ofs_file_out.close();
}
