#include <iostream>
#include <limits>

using namespace std;

const long  mod = 1000000007LL;

typedef long long ll;

long powMod(ll n, ll exp) {
    long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * n) % mod;
        n = (n * n) % mod;
        exp /= 2;
    }
    return res;
}

long binomialModulo(ll n, ll k) {
    ll ret = 1;
    for (ll i = 1; i <= k; ++i)
        ret = (((ret * (n + 1 - i)) % mod) * powMod(i, mod - 2)) % mod;
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ll T, N, M;

    cin >> T;
    for (ll i = 0; i < T; ++i) {
        cin >> N >> M;
        cout << binomialModulo(N + M - 1, N) << endl;
    }
    return 0;
}