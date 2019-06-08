#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    string line;
    while(getline(cin, line)) {
        vector<int> numbers;
        stringstream ss(line);
        int temp;
        while(ss >> temp) {
            numbers.push_back(temp);
        }
        sort(numbers.begin(), numbers.end());
        vector<int> rulerLengths;
        rulerLengths.push_back(0);
        for (int i = 0; i < numbers.size() - 1; ++i) {
            for (int j = i+1; j < numbers.size(); ++j) {
                rulerLengths.push_back(numbers[j]-numbers[i]);
            }
        }
        set<int> rulerLengthsSet(rulerLengths.begin(), rulerLengths.end());
        if (rulerLengthsSet.size() != rulerLengths.size()) {
            cout << "not a ruler" << endl;
            continue;
        }

        int ma = *max_element(rulerLengths.begin(), rulerLengths.end());
        if (rulerLengths.size()-1 == ma) {
            cout << "perfect" << endl;
            continue;
        }

        cout << "missing" << " ";
        for (int i = 0; i < ma; ++i) {
            if(rulerLengthsSet.find(i) == rulerLengthsSet.end()) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}