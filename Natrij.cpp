#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    string first, second, result;
    cin >> first >> second;
    int resultNumber;
    int firstHour, firstMinute, firstSecond;
    int secondHour, secondMinute, secondSecond;
    int resultHour, resultMinute, resultSecond;
    firstHour = stoi(first.substr(0, 2));
    firstMinute = stoi(first.substr(3, 2));
    firstSecond = stoi(first.substr(6, 2));
    secondHour = stoi(second.substr(0, 2));
    secondMinute = stoi(second.substr(3, 2));
    secondSecond = stoi(second.substr(6, 2));

    // Second:
    if (firstSecond <= secondSecond) {
        resultSecond = secondSecond - firstSecond;
    }
    else {
        resultSecond = (60-firstSecond) + secondSecond;
        firstMinute++;
    }

    // Minute:
    if (firstMinute <= secondMinute) {
        resultMinute = secondMinute - firstMinute;
    }
    else {
        resultMinute = (60-firstMinute) + secondMinute;
        firstHour++;
    }

    // Hour
    if (firstHour < secondHour) { // not quite sure why this was needed, but okay
        resultHour = secondHour - firstHour;
    }
    else {
        resultHour = (24-firstHour) + secondHour;
    }

    string h = to_string(resultHour), m = to_string(resultMinute), s = to_string(resultSecond);
    if (h.length() == 1) {
        h = "0"+h;
    }
    if (m.length() == 1) {
        m = "0"+m;
    }
    if (s.length() == 1) {
        s = "0"+s;
    }
    cout << h + ":" + m + ":" + s << endl;
    return 0;
}

// 20:00:00
// 04:00:00
// 07:59:60 if not equal or less.