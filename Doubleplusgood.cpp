#include <iostream>
#include "bits/stdc++.h"

using namespace std;


vector<int> plusPosition;
vector<int> combination;
set<long> allCombinations;
string line;

void eval(string expr) {
    replace(expr.begin(), expr.end(), '+', ' ');
    stringstream ss(expr);
    long total = 0, temp;
    while (ss >> temp) {
        total += temp;
    }
    allCombinations.insert(total);
}

void makeCombinations(int offset, int k) {
    if (k == 0) {
        string delStr = line;
        string result;
        for (auto &plusInd : combination) {
            delStr[plusInd] = 'D';
        }
        remove_copy(delStr.begin(), delStr.end(), back_inserter(result), 'D');
        // here we need to eval it:
        eval(result);
        return;
    }
    for (int i = offset; i <= plusPosition.size() - k; ++i) {
        combination.push_back(plusPosition[i]);
        makeCombinations(i + 1, k - 1);
        combination.pop_back();
    }
}

int main() {
    cin >> line;
    eval(line);
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == '+') {
            plusPosition.push_back(i);
        }
    }

    for (int i = 1; i < plusPosition.size() + 1; ++i) {
        makeCombinations(0, i);
    }
    cout << allCombinations.size() << endl;

    return 0;
}
