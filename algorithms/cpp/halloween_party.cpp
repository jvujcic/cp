#include <iostream>

using namespace std;

long long maxChocolate(int k) {
    long long half = k / 2;
    return half * (k - half);
}

int main() {
    int T, K;
    cin >> T;
    while (T--) {
        cin >> K;
        cout << maxChocolate(K) << endl;
    }

    return 0;
}