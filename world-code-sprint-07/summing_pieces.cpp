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

    vector<i64> v(n);

    for (i64 i = 0; i < n; ++i)
        cin >> v[i];

    vector<i64> pow_2(n+1);
    pow_2[0] = 1;
    for (i64 i = 1; i <= n; ++i) {
        pow_2[i] = (pow_2[i-1] * 2) % mod;
    }

    i64 x = pow_2[n];
    i64 sol = (v[0] * (pow_2[n] - 1)) % mod;
    if (n > 1) sol += (v[n-1] * (pow_2[n] - 1)) % mod;

    for (i64 i = 1; i < n / 2.; ++i) {
        x += pow_2[n-1-i];
        sol += (v[i] * (x - pow_2[i])) % mod;
        if (i != n - i - 1) sol += (v[n-i-1] * (x - pow_2[i])) % mod;
        sol %= mod;
    }
    if (sol < 0) sol += mod;
    cout << sol  << endl;

    return 0;
}