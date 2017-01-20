#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

i64 maxpow2(i64 n) {
    i64 pow2 = 1;
    for( ; 2 * pow2 <= n; pow2 *= 2);
    return pow2;
}

void print(const vector<i64> & v) {
    for (i64 x : v)
        cout << x << " ";
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);

    i64 n, m;
    cin >> n >> m;

    vector<i64> v(n);
    vector<i64> w(n);

    for (i64 & x : v)
        cin >> x;

    bool flag = true;
    --m;

    while (m > 0) {
        i64 pow2 = maxpow2(m);
        if (flag) {
            for (int i = 0; i < n; ++i)
                w[i] = v[i] ^ v[(i+pow2) % n];
            flag = !flag;
        }
        else {
            for (int i = 0; i < n; ++i)
                v[i] = w[i] ^ w[(i+pow2) % n];
            flag = !flag;
        }
        m = m - pow2;
    }

    if (flag) print(v);
    else print(w);

    return 0;
}