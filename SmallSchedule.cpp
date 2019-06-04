#include <iostream>
#include "bits/stdc++.h";

using namespace std;

int main() {
    int longtime, nMachines, nQuick, nLong;
    long long total = 0;
    cin >> longtime >> nMachines >> nQuick >> nLong;

    int fullLongs = nLong / nMachines;
    total += fullLongs*longtime;
    int longRemaining = nLong % nMachines;
    if (longRemaining > 0) {
        total += longtime;
        nQuick -= (nMachines-longRemaining)*longtime;
    }

    if (nQuick > 0) {
        total += nQuick/nMachines;
        if (nQuick%nMachines > 0) {
            total++;
        }
    }

    cout << total << endl;
    return 0;
}
