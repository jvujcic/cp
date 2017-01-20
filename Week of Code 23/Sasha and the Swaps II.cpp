#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

const i64 mod = 1000000007LL;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);

    i64 n;
    cin >> n;
    vector<vector<i64>> T(2, vector<i64>(n+1));
    vector<i64> fac(n+1);

    fac[0] = 1;
    T[0][0] = T[0][1] = T[0][2] = 1;

    for (i64 i = 1; i <= n; ++i)
        fac[i] = (i * fac[i-1]) % mod;

    for (i64 i = 3; i <= n; ++i) {
        i64 x = (i + 1) & 1;
        i64 y = i & 1;
        i64 last_three = (fac[i] * 500000004) % mod;
        T[y][i] = T[y][i-1] = T[y][i-2] = last_three;
        T[y][0] = 1;
        for (i64 j = 1; j < i-2; ++j)
            T[y][j] = (T[x][j] + (i - 1) * T[x][j-1]) % mod;
    }

    i64 what = n % 2;
    for (i64 i = 1; i < n; ++i)
        cout << T[what][i] << " ";
    
    return 0;
}