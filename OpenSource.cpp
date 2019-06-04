#include <iostream>
#include "bits/stdc++.h";
using namespace std;

int main() {
    set<string> hasVoted;
    set<string> votedTwice;
    map<string, set<string>> mapCount;
    string currentUni = "";
    while (true) {
        string inp;
        getline(cin, inp);

        if (isupper(inp.front())) {
            currentUni = inp;
            mapCount[currentUni].insert(currentUni);
        }
        else if (islower(inp.front())) {
            if (mapCount[currentUni].find(inp) != mapCount[currentUni].end()) {
                continue;
            }
            if (hasVoted.find(inp) != hasVoted.end()) {
                votedTwice.insert(inp);
                continue;
            }
            mapCount[currentUni].insert(inp);
            hasVoted.insert(inp);
        }
        else if (inp.front() == '1') {

            vector<pair<string, int>> overview;
            for(pair<string, set<string>> element : mapCount) {
                string uni = element.first;
                set<string> votes = element.second;
                vector<string> totalVotes;
                set_difference(votes.begin(), votes.end(), votedTwice.begin(), votedTwice.end(), back_inserter(totalVotes));
                overview.push_back(make_pair(uni, totalVotes.size()-1));
                totalVotes.clear();
            }

            sort(overview.begin(), overview.end(), [](auto &left, auto &right) {
                if (left.second == right.second) {
                    return left.first < right.first;
                }
                return left.second > right.second;
            });

            for(auto it = overview.begin(); it != overview.end(); it++) {
                pair<string, int> p = *it;
                cout << p.first << " " << p.second << endl;
            }

            hasVoted.clear();
            votedTwice.clear();
            mapCount.clear();
            string currentUni = "";
        }
        else {
            break; //exit
        }
    }
    return 0;
}