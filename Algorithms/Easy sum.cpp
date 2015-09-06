#include <iostream>

using namespace std;

typedef long long LL;

int main() {
    //freopen("input.txt", "r", stdin);

    LL T;
    cin >> T;
    
    for (LL i = 0; i < T; ++i) {
        LL N, m;
        cin >> N >> m;
        LL r = N % m;
        LL q = N / m;
        cout << q * (m * (m - 1)) / 2 + (r * (r + 1)) / 2<< endl;
    }
    return 0;
}