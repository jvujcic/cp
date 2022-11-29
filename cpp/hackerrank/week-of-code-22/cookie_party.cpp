#include <iostream>

using namespace std;

typedef long long LL;

int main() {
    freopen("input.txt", "r", stdin);

    LL n, m;
    cin >> n >> m;
    LL d = m / n;

    if (d * n == m) {
        cout << 0 << endl;
    }
    else {
       cout << (d + 1) * n - m << endl;
    }

    return 0;
}
