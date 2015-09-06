#include <iostream>
#include <array>
#include <functional>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (long long i = 0; i < T; ++i) {
        long N;
        cin >> N;
        long long result = 0;
        for (long long j = 0; j < N; ++j) {
            long long x;
            cin >> x;
            if (((j + 1) * (N - j)) % 2 == 1) result ^= x;
        }
        cout << result << endl;
    }

    return 0;
}