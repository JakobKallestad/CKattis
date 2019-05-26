//
// Created by Jakob Kallestad on 2019-05-26.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string inp;
    cin >> inp;
    int t=0, c=0, g=0;
    for (auto i : inp) {
        if (i == 'T') {
            t++;
        }
        if (i == 'C') {
            c++;
        }
        if (i == 'G') {
            g++;
        }
    }
    int sum = (t*t) + (c*c) + (g*g) + min(t, min(g, c))*7;
    cout << sum << endl;
    return 0;
}