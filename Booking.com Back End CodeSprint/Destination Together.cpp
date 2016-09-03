#include <iostream>

using namespace std;

using ll = long long;

ll factorial(ll n) {
    ll fac = 1;
    for (ll i = 1; i <= n; ++i)
        fac *= i;
    return fac;
}

int main() {
    freopen("input.txt", "r", stdin);

    ll n, m, c;

    cin >> n >> m >> c;

    cout << factorial(n + m - c - 1) << endl;

    return 0;
}
