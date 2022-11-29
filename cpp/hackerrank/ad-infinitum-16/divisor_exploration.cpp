#include <bits/stdc++.h>
#include <cmath>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;


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


int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);
    i64 D;
    cin >> D;

    const i64 max_m = 100000LL;
    const i64 max_a = 100000LL;
    const i64 mod = 1000000007LL;

    vector<i64> pow_two_inverse(max_m + 1);
    vector<i64> fact(2 * max_a + 3);
    vector<i64> solutions(D);

    for (i64 n = 1, i = 0; i <= max_m; ++i) {
        pow_two_inverse[i] = inverse_mod(n, mod);
        n = (2 * n) % mod;
    }

    fact[0] = 1;

    for (i64 i = 1; i < 2 * max_a + 3; ++i)
        fact[i] = (i * fact[i - 1]) % mod;


    for (i64 i = 0; i < D; i++) {
        i64 m, a;
        cin >> m >> a;
        i64 solution = (fact[a + m + 1] * inverse_mod(fact[a + 2], mod)) % mod;
        solution = (solution * solution) % mod;
        solution = (solution * (a + 2)) % mod;
        solution = (solution * (a + m + 2)) % mod;
        solution = (solution * pow_two_inverse[m]) % mod;
        solutions[i] = solution;
    }

    for (auto n : solutions) cout << n << "\n";

    return 0;
}
