#include <iostream>
#include "bits/stdc++.h";
using namespace std;


set<int> canMake;
map<int, set<int>> anglesMap;
vector<int> combination;
vector<int> knows, wants;

// Makes all the combinations of using k-elements from the knows-vector.
void go(int offset, int k) {
    if (k == 0) {
        int soe = accumulate(combination.begin(), combination.end(), 0)%360;
        set<int> result;
        set_union(canMake.begin(), canMake.end(), anglesMap[soe].begin(), anglesMap[soe].end(), inserter(result, result.begin()));
        canMake = result;
        return;
    }
    for (int i = offset; i <= knows.size() - k; ++i) {
        combination.push_back(knows[i]);
        go(i+1, k-1);
        combination.pop_back();
    }
}

int main() {

    // INPUT
    int nKnows, nWants;
    cin >> nKnows >> nWants;
    int temp;
    for (int i = 0; i < nKnows; ++i) {
        cin >> temp;
        knows.push_back(temp);
    }
    for (int j = 0; j < nWants; ++j) {
        cin >> temp;
        wants.push_back(temp);
    }

    // ALL POSSIBLE ANGLES THAT CAN BE MADE FROM JUST "SPAMMING" ONE ANGLE
    for (int k = 1; k < 360; ++k) {
        int currentAng = (k+k)%360;
        while(currentAng != k) {
            anglesMap[k].insert(currentAng);
            currentAng = (currentAng+k)%360;
        }
    }

    // CALCULATE ALL THE SUMS OF COMBINATIONS OF THE KNOWN ANGLES,
    // THEN UPDATE THE canMake BASED ON THE POSSIBLE ANGLES YOU CAN GET BY
    // "SPAMMING" THAT ANGLE
    for (int l = 1; l < nKnows + 1; ++l) {
        go(0, l);
    }


    // OUTPUT
    for (int m = 0; m < nWants; ++m) {
        if (canMake.find(wants[m]) != canMake.end()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}