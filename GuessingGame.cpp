#include <iostream>
#include "bits/stdc++.h";
using namespace std;

int main() {
    int high = 11, low = 0;
    vector<bool> lies;
    bool lying = false;
    int num;
    string reply;
    cin >> num;
    while (num) {
        getline(cin, reply); // clear end of line
        getline(cin, reply);
        if (reply == "too high") {
            if (num <= low) {
                lying = false;
            }
            if (high == 11) {
                high = num;
            }
            else {
                high = min(high, num);
            }
        }
        else if (reply == "too low") {
            if (num >= high) {
                lying = true;
            }
            if (low == 0) {
                low = num;
            }
            else {
                low = max(low, num);
            }
        }
        else {
            if (num <= low || num >= high) {
                lying = true;
            }
            lies.push_back(lying);
            high = 100, low = -1, lying = false;
        }
        cin >> num;
    }
    for (bool b : lies) {
        b ? cout << "Stan is dishonest" << endl : cout << "Stan may be honest" << endl;
    }
    return 0;
}