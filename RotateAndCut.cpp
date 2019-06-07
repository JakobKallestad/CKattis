#include <iostream>
#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int nRotates, remove, curSize, startInd = 0, endInd;
        string line;
        cin >> nRotates >> line;
        endInd = curSize = line.length();
        for (int i = 0; i < min(nRotates, 24); ++i) {
            remove = curSize / 4;
            if (i % 2 == 0) {
                startInd += remove;
            }
            else {
                endInd -= remove;
            }
            curSize -= remove;
        }
        cout << line.substr(startInd, endInd - startInd) << endl;
    }
}