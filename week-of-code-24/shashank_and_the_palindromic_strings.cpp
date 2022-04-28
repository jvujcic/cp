#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

const i64 mod = 1000000007LL;


void solve() {
    i64 n;
    cin >> n;
    string str;
    unordered_map<i64, i64> index;

    for (i64 i = 0; i < n; ++i) {
        i64 last = str.size();
        string s;
        cin >> s;
        str += s;
        for (i64 j = last; j < str.size(); ++j)
            index[j] = i;
    }

    i64 m = str.size();
    vector<vector<vector<i64>>> pal(m, vector<vector<i64>>(m, vector<i64>(n+1)));
    vector<vector<i64>> count(m, vector<i64>(m));
    vector<vector<bool>> included(m, vector<bool>(m, false));

    for (i64 i = 0; i < m; ++i) {
        pal[i][i][1] = 1;
        included[i][i] = true;
    }

    for (i64 j = 1; j < m; ++j) {
        for (i64 i = 0; i + j < m; ++i) {
            for (i64 k = 1; k < n + 1; ++k) {
                i64 l = pal[i][i+j-1][k];
                i64 r = pal[i+1][i+j][k];
                i64 m = pal[i+1][i+j-1][k];
                if(index[i] == index[i+1] && index[i+j] == index[i+j-1]) {
                    pal[i][i+j][k] = r + l - m;// + (str[i] == str[i+j] ? 1 : 0) * (m + 1);
                    if (str[i] == str[i+j] && index[i+j] - index[i] + 1 == k) pal[i][i+j][k] = m + 1;
                    if (str[i] == str[i+j] && index[i+j] - index[i] == k) pal[i][i+j][k+1] = m;
                }
                else if (index[i] == index[i+1] && index[i+j] != index[i+j-1]) {
                    pal[i][i+j][k] = r + l - m;
                    if (str[i] == str[i+j] && k+1 <= n) pal[i][i+j][k+1] += m + 1;
                }
                else if (index[i] != index[i+1] && index[i+j] == index[i+j-1]) {
                    pal[i][i+j][k] = r + l - m;
                    if (str[i] == str[i+j] && k+1 <= n) pal[i][i+j][k+1] += m + 1;
                }
                else {
                    pal[i][i+j][k] = r + l - m;
                    if (str[i] == str[i+j] && k+2 <= n) pal[i][i+j][k+2] += m;
                }
            }
        }
    }

    for (i64 k = 1; k <= n; k++) {
        for (i64 i = 0; i < m; i++) {
            for (i64 j = 0; j < m; j++)
                cout << pal[i][j][k] << " ";
            cout << endl;
        }
        cout << endl << endl;
    }
    cout << pal[0][m-1][n] << endl;
}


int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);

    i64 q;
    cin >> q;

    for (int i = 0; i < q; ++i)
        solve();

    return 0;
}