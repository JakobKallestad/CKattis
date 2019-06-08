#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    int nLines;
    bool first = true;
    while(cin >> nLines && nLines != 0) {
        cin.ignore();
        if(!first) {
            cout << endl;
        }
        else {
            first = false;
        }
        string line;
        char firstSymbol;
        bool currentSym; // hash
        bool error = false;
        int lineLength = -1;
        for (int i = 0; i < nLines; ++i) {
            int currentLineLength = 0;
            getline(cin, line);
            vector<string> resultLine;
            stringstream ss(line);
            ss >> firstSymbol;
            if (firstSymbol == '#') {
                currentSym = true;
            }
            else {
                currentSym = false;
            }
            int temp;
            while(ss >> temp) {
                string output = "";
                currentLineLength += temp;
                char addChar = currentSym ? '#' : '.';
                for (int j = 0; j < temp; ++j) {
                    output += addChar;
                }
                cout << output;
                currentSym = !currentSym;
            }
            cout << endl;
            if(lineLength == -1) {
                lineLength = currentLineLength;
            }
            if(currentLineLength != lineLength) {
                error = true;
            }
        }
        if(error) {
            cout << "Error decoding image" << endl;
        }
    }
    return 0;
}