#include <iostream>
#include "bits/stdc++.h"

using namespace std;

int main() {
    string inp;
    map<string, int> wordToValue;
    while(getline(cin, inp) && inp != "0") {
        if (inp.find('=') != string::npos) {
            vector<string> wList;
            stringstream ss(inp);
            string key;
            ss >> key;
            string value;
            ss >> value;
            ss >> value;
            wordToValue[key] = stoi(value);
        }
        else {
            vector<string> wList;
            stringstream ss(inp);
            string temp;
            bool isNum = false;
            int sum = 0; // be aware of maybe adding only 0's
            while (ss >> temp) {
                if(temp == "+") {
                    continue;
                }
                else if(wordToValue.find(temp) != wordToValue.end()) {
                    sum += wordToValue[temp];
                    isNum = true;
                }
                else if (!isdigit(temp[0])) {
                    wList.push_back(temp);
                }
                else {
                    sum += stoi(temp);
                    isNum = true;
                }
            }

            if(isNum) {
                cout << sum;
            }
            if(wList.size() != 0) {
                if(isNum) {
                    cout << " + ";
                }
                for (int i = 0; i < wList.size()-1; ++i) {
                    cout << wList[i] << " + ";
                }
                cout << wList[wList.size()-1];
            }
            cout << endl;
        }
    }
    return 0;
}