#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);
    i64 n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<i64>> radii(n, vector<i64>(n));

    for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') {
                radii[i][j] = -1;
            }
            else {
                vector<i64> v = {i, j, n - i - 1, n - j - 1};
                radii[i][j] = *min_element(v.begin(), v.end());
            }
        }
    }

    for (i64 i = 0; i < n; ++i)
        for (i64 j = 0; j < n; ++j)
            for (i64 k = 0; k < n; ++k)
                for (i64 l = 0; l < n; ++l) {
                    i64 h = (k-i)*(k-i) + (l-j)*(l-j);
                    i64 r = sqrt(h);
                    if (r*r == h) r-=1;
                    if (grid[k][l] == '*' && r < radii[i][j])
                        radii[i][j] = r;
                }

    i64 solution = 0;
    for (i64 i = 0; i < n; ++i)
        for (i64 j = 0; j < n; ++j)
            if (radii[i][j] > solution) solution = radii[i][j];

    cout << solution << endl;


    return 0;
}