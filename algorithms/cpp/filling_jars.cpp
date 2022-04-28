#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    long long sum = 0;
    while(M--) {
        long long a, b, k;
        cin >> a >> b >> k;
        sum += (b - a + 1) * k;
    }
    cout << sum / N;

    return 0;
}