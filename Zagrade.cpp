#include <iostream>
#include "bits/stdc++.h"
using namespace std;


vector<pair<int, int>> bracketPositions;
vector<pair<int, int>> combination;
set<string> allCombinations;
string line;

void makeCombinations(int offset, int k) {
    if (k == 0) {
        string delStr = line;
        string result;
        for (auto &bracket : combination) {
            delStr[bracket.first] = 'D';
            delStr[bracket.second] = 'D';
        }
        remove_copy(delStr.begin(), delStr.end(), back_inserter(result), 'D');
        allCombinations.insert(result);
        return;
    }
    for (int i = offset; i <= bracketPositions.size() - k; ++i) {
        combination.push_back(bracketPositions[i]);
        makeCombinations(i + 1, k - 1);
        combination.pop_back();
    }
}

int main() {
    cin >> line;
    stack<int> myStack;
    for (int i = 0; i < line.length(); ++i) {
        if(line[i] == '(') {
            myStack.push(i);
        }
        else if (line[i] == ')') {
            bracketPositions.push_back(make_pair(myStack.top(), i));
            myStack.pop();
        }
    }

    for (int i = 1; i < bracketPositions.size()+1; ++i) {
        makeCombinations(0, i);
    }

    vector<string> allCombs(allCombinations.begin(), allCombinations.end());
    sort(allCombs.begin(), allCombs.end());
    for(auto l : allCombs) {
        cout << l << endl;
    }

    return 0;
}