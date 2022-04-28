#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

const i64 mod = 1000000007LL;
const i64 max_size = 1000000;
vector<i64> fact(max_size);
vector<i64> inverse_fact(max_size);

i64 inverse_mod(const i64 & a, const i64 & m) {
    i64 t = 0, r = m, new_t = 1, new_r = a, tmp;

    while (new_r != 0) {
        i64 q = r / new_r;
        tmp = t;
        t = new_t;
        new_t = tmp - q * new_t;
        tmp = r;
        r = new_r;
        new_r = tmp - q * new_r;
    }

    if (t < 0) t += m;

    return t;
}

i64 bin_mod(const i64 & n, const i64 & m) {
    if (m == 0) return 1;
    if (n == m) return 1;

    return (((fact[n] * inverse_fact[m]) % mod) * inverse_fact[n - m]) % mod;
}

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);


    fact[0] = 1;
    inverse_fact[0] = 1;

    for (i64 i = 1; i < max_size; ++i) {
        fact[i] = (i * fact[i - 1]) % mod;
        inverse_fact[i] = inverse_mod(fact[i], mod);
    }

    i64 t;
    cin >> t;

    for (i64 ti = 0; ti < t; ++ti) {
        i64 x, y, z;
        cin >> x >> y >> z;

        vector<vector<i64>> num_of_path(x + 1, vector<i64>(y + 1));

        for (i64 i = 0; i < x; ++i)
            num_of_path[i][0] = 1;

        for (i64 j = 0; j < y; ++j)
            num_of_path[0][j] = 1;

        for (i64 i = 1; i < x; ++i)
            for (i64 j = 1; j < y; ++j)
                num_of_path[i][j] = (num_of_path[i - 1][j] + num_of_path[i][j - 1]) % mod;

        i64 solution = 0;

        for (i64 i = 0; i < x; ++i) {
            for (i64 j = 0; j < y; ++j) {
                i64 fly_paths = 0;
                i64 a = x - i - 1, b = y - j - 1;
                i64 mini = min(min(a, b), z - 1);
                //cout << mini << endl;
                for (i64 k = 0; k <= mini; ++k) {
                    fly_paths = (fly_paths + ((((bin_mod(a, k)*bin_mod(b, k))%mod)*bin_mod(z - 1, k)) % mod)) % mod;
                }
                cout << i << " " << j << " " << num_of_path[i][j] << " " << fly_paths << endl;
                solution += ((num_of_path[i][j] * fly_paths) % mod);
            }
        }
        cout << solution << "\n";
    }

    return 0;
}
