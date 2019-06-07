#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, m, k, temp;
    cin >> n >> m >> k;
    vector<int> plots;
    vector<double> circles;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        plots.push_back(temp);
    }
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        circles.push_back(temp);
    }
    for (int i = 0; i < k; ++i) {
        cin >> temp;
        double radius = (temp * sqrt(2))/2;
        circles.push_back(radius);
    }
    sort(plots.rbegin(), plots.rend());
    sort(circles.rbegin(), circles.rend());
    int i = 0, j = 0, count = 0;
    while (i < plots.size() && j < circles.size()) {
        if (circles[j] < plots[i]) {
            count++;
            j++;
            i++;
        }
        else {
            j++;
        }
    }
    cout << count << endl;
    return 0;
}