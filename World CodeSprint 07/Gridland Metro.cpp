#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);

    i64 n, m, k;
    cin >> n >> m >> k;

    i64 sol = n * m;

    unordered_map<i64, vector<pair<i64, i64>>> trains;

    for (i64 i = 0; i < k; ++i) {
        i64 r, c1, c2;
        cin >> r >> c1 >> c2;
        auto it = trains.find(r);
        if (it == trains.end()) {
            trains[r] = {{c1, -1}, {c2, 1}};
        }
        else {
            trains[r].emplace_back(c1, -1);
            trains[r].emplace_back(c2, 1);
        }
    }

    for (auto & p : trains) {
        sort(p.second.begin(), p.second.end());
        i64 cnt = 0;
        i64 start = -1;
        for (auto & point : p.second) {
            if (point.second == -1) ++cnt;
            else --cnt;
            if (cnt > 0 && start == -1) start = point.first;
            if (cnt == 0) {
                sol -= point.first - start + 1;
                start = -1;
            }
        }
    }

    cout << sol << endl;

    return 0;
}