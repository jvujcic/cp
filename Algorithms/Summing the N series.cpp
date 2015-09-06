#include <iostream>

using namespace std;

typedef long long LL;
const LL mod = 1E9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);

    LL T, n;

    cin >> T;

    for (LL i = 0; i < T; ++i) {
        cin >> n;
        cout << ((n % mod) * (n % mod)) % mod << endl;
    }

    return 0;
}