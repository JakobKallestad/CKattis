#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main() {
    int nStudents, target;
    cin >> nStudents >> target;
    vector<int> students;
    int temp, theirScore = 0;
    for (int i = 0; i < nStudents; ++i) {
        cin >> temp;
        theirScore += temp;
        students.push_back(temp);
    }

    if (theirScore == target*nStudents) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = nStudents+1; i < 10000; ++i) {
        int missingScore = target*i - theirScore;
        double perStudent = (double)missingScore/(i-nStudents);
        if (perStudent <= 100 && perStudent >= 0) {
            cout << i-nStudents << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;

    return 0;
}