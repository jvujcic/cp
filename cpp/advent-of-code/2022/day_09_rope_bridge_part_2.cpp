#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

int main() {
    char direction;
    ll num_of_steps;

    unordered_set<pair<ll, ll>, hash_pair> seen;
    pair<ll, ll> knots[10] = {{0LL, 0LL}};

    while (cin >> direction >> num_of_steps) {
        for (ll i = 0; i < num_of_steps; ++i) {
            switch (direction) {
                case 'R':
                    knots[0].first++;
                    break;
                case 'L':
                    knots[0].first--;
                    break;
                case 'U':
                    knots[0].second++;
                    break;
                case 'D':
                    knots[0].second--;
            }

            for (int j = 1; j < 10; ++j) {
                ll difx = knots[j - 1].first - knots[j].first;
                ll dify = knots[j - 1].second - knots[j].second;

                if (abs(difx) == 2 && abs(dify) == 2) {
                    knots[j].first += (difx / 2);
                    knots[j].second += (dify / 2);
                } else if (abs(difx) == 2) {
                    knots[j].first += (difx / 2);
                    knots[j].second += dify;
                } else if (abs(dify) == 2) {
                    knots[j].first += difx;
                    knots[j].second += (dify / 2);
                }
            }

            seen.insert(knots[9]);
        }
    }

    cout << seen.size() << endl;
    return 0;
}
