#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    int w, n, total = 0, wi, li;
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        cin >> wi >> li;
        total += wi*li;
    }
    cout << total/w << endl;
    return 0;
}