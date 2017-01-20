#include <bits/stdc++.h>
#include <cmath>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);

    i64 n, m;
    cin >> n >> m;

    vector<vector<i64>> points(m, vector<i64>(n));

    for (i64 i = 0; i < n; ++i)
        for (i64 j = 0; j < m; ++j)
            cin >> points[j][i];

    for (i64 i = 0; i < m; ++i) {
        sort (points[i].begin(), points[i].end());
        cout << points[i][n % 2 ? n / 2 : n /2 - 1] << " ";
    }

    return 0;
}
