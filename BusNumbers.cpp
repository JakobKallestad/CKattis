#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    vector<int> cubeNums;
    for (int i = 1; i < 74; ++i) {
        cubeNums.push_back(i*i*i);
    }

    vector<int> cubeTwoSums;
    map<int, int> checker;
    for (int i = 0; i < 72; ++i) {
        for (int j = i+1; j < 73; ++j) {
            int su = cubeNums[i]+cubeNums[j];
            if(!checker.count(su)) {
                checker[su] = 1;
            }
            else {
                if(checker[su] == 1) {
                    cubeTwoSums.push_back(su);
                }
                checker[su]++;
            }
        }
    }
    sort(cubeTwoSums.begin(), cubeTwoSums.end());

    int inp;
    cin >> inp;
    if(inp<cubeTwoSums[0]) {
        cout << "none" << endl;
    }
    else {
        for (int i = 0; i < cubeTwoSums.size(); ++i) {
            if(inp<cubeTwoSums[i]) {
                cout << cubeTwoSums[i-1] << endl;
                break;
            }
        }
    }
    return 0;
}