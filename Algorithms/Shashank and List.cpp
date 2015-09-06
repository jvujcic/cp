#include <iostream>

using namespace std;

typedef long long LL;

const LL mod = 1E9 + 7;

LL powMod(LL n, LL exp) {
    LL res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * n) % mod;
        n = (n * n) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);

    LL N;
    cin >> N;

    LL result = 1;

    for (LL i = 0; i < N; ++i) {
        LL a;
        cin >> a;
        result = (result * (powMod(2, a) + 1)) % mod;
    }

    cout << result - 1 << endl;

    return 0;
}