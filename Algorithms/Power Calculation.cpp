#include <iostream>
#include <numeric>

using namespace std;

typedef long long LL;

LL powMod(LL n, LL exp, LL mod) {
    LL res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * n) % mod;
        n = (n * n) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);

    LL T;
    cin >> T;

    for (LL i = 0; i < T; ++i) {
        LL K, N;
        cin >> K >> N;
        LL lastTwoDigits[100];
        for (LL j = 0; j < 100; ++j)
            lastTwoDigits[j] = powMod(j, N, 100);
      
        LL sumOfDigits = accumulate(lastTwoDigits, lastTwoDigits + 100, 0LL) % 100;
        LL q = K / 100;
        LL r = K % 100;
        LL result = ((q % 100) * sumOfDigits + accumulate(lastTwoDigits, lastTwoDigits + r + 1, 0LL)) % 100;
        
        if (result < 10) cout << "0";
        cout << result << endl;
            
    }

    return 0;
}