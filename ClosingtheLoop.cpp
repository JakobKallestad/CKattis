#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int nKnots;
        vector<int> red, blue;
        cin >> nKnots;
        string temp;
        for (int j = 0; j < nKnots; ++j) {
            cin >> temp;
            if (temp[temp.size()-1] == 'R') {
                temp.pop_back();
                red.push_back(stoi(temp));
            } else {
                temp.pop_back();
                blue.push_back(stoi(temp));
            }
        }
        sort(red.rbegin(), red.rend());
        sort(blue.rbegin(), blue.rend());
        int total = 0;
        for (int j = 0; j < min(red.size(), blue.size()); ++j) {
            total += red[j];
            total += blue[j];
            total -= 2;
        }
        cout << "Case #" << (i+1) << ": " << total << endl;
    }
    return 0;
}