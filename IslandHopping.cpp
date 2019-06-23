#include <iostream>
#include "bits/stdc++.h"
using namespace std;

class UF {
    int *id, *sz;
    public:
    UF(int N) {
        id = new int[N]; sz = new int[N];
        for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }

    int find(int p) {
        while (p != id[p]) {
            p = id[p];
            id[p] = id[id[p]];
        }
        return p;
    }

    void merge(int x, int y) {
        int i = find(x); int j = find(y); if (i == j) return;
        if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
        else { id[j] = i, sz[i] += sz[j]; }
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {

    int n_test_cases;
    cin >> n_test_cases;
    for (int i = 0; i < n_test_cases; ++i) {
        vector<pair<float, float>> islands;
        int n_islands;
        cin >> n_islands;
        for (int j = 0; j < n_islands; ++j) {
            float y, x;
            cin >> y >> x;
            islands.push_back(make_pair(y, x));
        }

        vector<tuple<int, int, float>> distances;
        for (int k = 0; k < islands.size(); ++k) {
            for (int l = k+1; l < islands.size(); ++l) {
                float dist = sqrt(pow(islands[k].first-islands[l].first, 2) + pow(islands[k].second-islands[l].second, 2));
                distances.push_back(make_tuple(k, l, dist));
            }
        }

        sort(distances.begin(), distances.end(), [=](tuple<int, int, float>& a, tuple<int, int, float>& b) {
            return get<2>(a) < get<2>(b);
        });

        UF uf = UF(n_islands);
        float total_dist = 0;
        for (int j = 0; j < distances.size(); ++j) {
            if (!uf.connected(get<0>(distances[j]), get<1>(distances[j]))) {
                total_dist += get<2>(distances[j]);
                uf.merge(get<0>(distances[j]), get<1>(distances[j]));
            }
        }
        cout.precision(9);
        cout << total_dist << endl;
    }

    return 0;
}