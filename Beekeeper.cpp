#include <iostream>
#include "bits/stdc++.h"

using namespace std;

int key_search(const string &s, const string &key) {
    int count = 0;
    int pos = 0;
    while ((pos = s.find(key, pos)) != string::npos) {
        ++count;
        ++pos;
    }
    return count;
}

int main() {
    int nWords;
    while (cin >> nWords && nWords != 0) {
        string currentWord, bestWord;
        int score, bestScore = -1;
        for (int i = 0; i < nWords; ++i) {
            cin >> currentWord;
            score = 0;
            score += key_search(currentWord, "aa");
            score += key_search(currentWord, "ee");
            score += key_search(currentWord, "ii");
            score += key_search(currentWord, "oo");
            score += key_search(currentWord, "uu");
            score += key_search(currentWord, "yy");

            if (score > bestScore) {
                bestScore = score;
                bestWord = currentWord;
            }
        }
        cout << bestWord << endl;
    }
    return 0;
}