//
// Created by sberg on 17.04.2020.
//

#include <cmath>
#include <iostream>

using namespace std;

void cut(double& d1, double& d2);
void shift(string& s1, string& s2, string& s3);

int main(){
    double d1 = 1.2;
    double d2 = 1.4;
    cout << "d1 before cut: " << d1 << endl;
    cout << "d2 before cut: " << d2 << endl;
    cut(d1, d2);
    cout << "d1 after cut: " << d1 << endl;
    cout << "d2 after cut: " << d2 << endl;

    string s1 = "A";
    string s2 = "B";
    string s3 = "C";
    cout << "s1 before shift: " << s1 << endl;
    cout << "s2 before shift: " << s2 << endl;
    cout << "s3 before shift: " << s3 << endl;
    shift(s1, s2, s3);
    cout << "s1 after shift: " << s1 << endl;
    cout << "s2 after shift: " << s2 << endl;
    cout << "s3 after shift: " << s3 << endl;

}

void cut(double& d1, double& d2) {
    d1 = floor(d1);
    d2 = floor(d2);
}

void shift(string& s1, string& s2, string& s3) {
    string temp = s1;
    s1 = s2;
    s2 = s3;
    s3 = temp;
}