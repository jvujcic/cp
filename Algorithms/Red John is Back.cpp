#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int wallCombinations(int N) {
    vector<int> v(N + 4);
    v[1] = v[2] = v[3] = 1;
    v[4] = 2;
    for (int i = 5; i <= N; ++i)
        v[i] = v[i - 1] + v[i - 4];

    return v[N];
}

int numberOfPrimes(int N) {
    vector<bool> sieve(N + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i < sqrt(N) + 1; ++i)
        if (sieve[i])
            for (int j = 2 * i; j <= N; j += i)
                sieve[j] = false;
    
    return count(sieve.begin(), sieve.end(), true);
}

int main() {
    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        cout << numberOfPrimes(wallCombinations(N)) << endl;
    }

    return 0;
}