#include <iostream>
#include "bits/stdc++.h"
using namespace std;

void createVocab(vector<string> &words, int depth, string &currentWord) {
    if(depth == 4) {
        words.push_back(currentWord);
        return;
    }
    for (int i = 97; i < 123; ++i) {
        currentWord[depth] = i;
        createVocab(words, depth+1, currentWord);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<string> words;
    string currentWord = "    ";
    createVocab(words, 0, currentWord);
    for (int i = 0; i < b; ++i) {
        cout << words[i] << " ";
    }
    cout << endl;
    return 0;
}