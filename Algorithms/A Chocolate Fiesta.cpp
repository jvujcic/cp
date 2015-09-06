#include <iostream>
#include <cstdint>

using namespace std;

const int64_t  mod = 1000000007;

int64_t powMod(int64_t n, int64_t exp) {
    int64_t res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * n) % mod;
        n = (n * n) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);

    int64_t N;
    cin >> N;

    int64_t odd = 0;
    int64_t even = 0;

    for (int64_t i = 0; i < N; ++i) {
        int64_t a;
        cin >> a;
        if (a % 2 == 0) ++even;
        else ++odd;
    }

    int64_t result = 0;
    int64_t oddSub = powMod(2, odd - 1);
    int64_t evenSub = powMod(2, even);

    if (odd < 2) result = evenSub - 1;
    else if (even == 0) result = oddSub - 1;
    else result = ((evenSub * oddSub) - 1) % mod;
   
    cout << result << endl;
    return 0;
}
