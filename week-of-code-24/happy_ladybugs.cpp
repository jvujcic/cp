#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

void solve() {
    vector<i64> letters('Z' - 'A' + 1);
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    i64 num_dash = 0;
    for_each(s.begin(), s.end(), [&](char c) {
        if (c == '_') ++num_dash;
        else ++letters[c - 'A'];
    });

    if (find(letters.begin(), letters.end(), 1) != letters.end()) {
        cout << "NO" << endl;
        return;
    }

    if (num_dash == 0) {
        if (s[0] != s[1]) {
            cout << "NO" << endl;
            return;
        }
        else if (s[n-1] != s[n-2]) {
            cout << "NO" << endl;
            return;
        }
        for (i64 i = 1; i < n - 1; ++i) {
            if (s[i] != s[i-1] && s[i] != s[i+1]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);
    i64 g;
    cin >> g;

    for (i64 i = 0; i < g; ++i)
        solve();

    return 0;
}
