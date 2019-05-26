//
// Created by Jakob Kallestad on 2019-05-26.
//

#include <iostream>
#include "bits/stdc++.h";
using namespace std;

int main() {
    int n, least = 0, leastIndex = -1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int junk;
        cin >> junk;
        if (leastIndex == -1 || junk < least) {
            least = junk;
            leastIndex = i;
        }
    }
    cout << leastIndex << endl;
    return 0;
}