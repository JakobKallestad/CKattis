#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    int nCategories;
    cin >> nCategories;
    map<string, set<string>> categories;
    map<string, int> scoreMap;
    vector<string> cNames;
    for (int i = 0; i < nCategories; ++i) {
        string name;
        int nWords;
        cin >> name >> nWords;
        set<string> tempSet;
        string tempWord;
        for (int j = 0; j < nWords; ++j) {
            cin >> tempWord;
            tempSet.insert(tempWord);
        }
        categories[name] = tempSet;
        cNames.push_back(name);
        scoreMap[name] = 0;
    }

    cin.ignore();
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        string tempWord;
        while(ss >> tempWord) {
            for(auto name : cNames) {
                if(categories[name].find(tempWord) != categories[name].end()) {
                    scoreMap[name]++;
                }
            }
        }
    }

    vector<pair<string, int>> pairs;
    for (auto itr = scoreMap.begin(); itr != scoreMap.end(); ++itr) {
        pairs.push_back(*itr);
    }

    sort(pairs.begin(), pairs.end(), [=](pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    int topScore = -1;
    for (int i = 0; i < pairs.size(); ++i) {
        if(topScore == -1) {
            topScore = pairs[i].second;
        }
        if(pairs[i].second < topScore) {
            break;
        }
        cout << pairs[i].first << endl;
    }

    return 0;
}