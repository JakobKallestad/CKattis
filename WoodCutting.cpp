#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int nPeople, nPieces, temp;
        cin >> nPeople;
        vector<long> people;
        for (int i = 0; i < nPeople; ++i) {
            cin >> nPieces;
            long total = 0;
            for (int j = 0; j < nPieces; ++j) {
                cin >> temp;
                total += temp;
            }
            people.push_back(total);
        }
        sort(people.begin(), people.end());
        long average = 0;
        long elapsedTime = 0;
        for (int i = 0; i < people.size(); ++i) {
            elapsedTime += people[i];
            average += elapsedTime;
        }
        //cout << fixed;
        cout.precision(9);
        cout << average/(double)people.size() << endl;
    }
    return 0;
}