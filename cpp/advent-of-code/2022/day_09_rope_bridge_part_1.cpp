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

    auto current_head = pair{0LL, 0LL};
    auto current_tail = pair{0LL, 0LL};

    unordered_set<pair<ll, ll>, hash_pair> seen;

    while (cin >> direction >> num_of_steps) {
        for (ll i = 0; i < num_of_steps; ++i) {
            switch (direction) {
                case 'R':
                    current_head.first++;
                    break;
                case 'L':
                    current_head.first--;
                    break;
                case 'U':
                    current_head.second++;
                    break;
                case 'D':
                    current_head.second--;
            }

            ll difx = current_head.first - current_tail.first;
            ll dify = current_head.second - current_tail.second;

            if (abs(difx) == 2 && abs(dify) == 2) {
                current_tail.first += (difx / 2);
                current_tail.second += (dify / 2);
            } else if (abs(difx) == 2) {
                current_tail.first += (difx / 2);
                current_tail.second += dify;
            } else if (abs(dify) == 2) {
                current_tail.first += difx;
                current_tail.second += (dify / 2);
            }

            seen.insert(current_tail);
        }
    }
    cout << seen.size() << endl;
    return 0;
}
