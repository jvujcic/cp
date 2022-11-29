#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);

    i64 n, m;
    cin >> n >> m;

    pair<i64, i64> current = {1, 0};

    for (i64 i = 0; i < m; ++i) {
        i64 type, k;
        cin >> type >> k;
        if (type == 2)
            k = n - k;
        if (type == 1 && current.first == 1) {
            current.second = (k + current.second) % n;
        }
        else if (type == 1 && current.first == 2) {
            current.second = (current.second - k) % n;
        }
        else if (type == 2 && current.first == 1) {
            current.first = 2;
            current.second = (current.second + k) % n;
        }
        else if (type == 2 && current.first == 2) {
            current.first = 1;
            current.second = (current.second - k) % n;
        }

        if (current.second < 0)
            current.second += n;
    }

    if (current.first == 1)
        cout << 1 << " " << n - current.second << endl;
    else
        cout << 2 << " " << n - current.second << endl;
    return 0;
}
