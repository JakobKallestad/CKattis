#include <iostream>
#include "bits/stdc++.h";
using namespace std;

int main() {
    int n;
    bool p1 = true;
    char matchChar = '-';
    cin >> n;
    set<string> words;
    for (int i = 0; i < n; ++i) {
        string w;
        cin >> w;
        if (words.find(w) != words.end() || (matchChar != '-' && w.front() != matchChar)) {
            if (p1) {
                cout << "Player 1 lost" << endl;
                return 0;
            }
            else {
                cout << "Player 2 lost" << endl;
                return 0;
            }
        }
        matchChar = w.back();
        words.insert(w);
        p1 = !p1;
    }
    cout << "Fair Game" << endl;
    return 0;
}