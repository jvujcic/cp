#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> s(101);

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        s[c]++;
    }

    int sol = 0;

    for (int x : s) {
        sol += x / 2;
    }

    cout << sol << endl;
    return 0;
}
