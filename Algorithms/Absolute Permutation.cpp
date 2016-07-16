#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N, K;
        cin >> N >> K;

        if (K == 0) {
            for (int j = 1; j <= N; j++)
                cout << j << " ";
            cout << endl;
            continue;
        }

        if (N % (2 * K) != 0) {
            cout << -1 << endl;
            continue;
        }


        vector<int> permutation(N + 1);

        for (int j = 1; j <= N; j += 2 * K) {
            for (int l = j; l < j + K; ++l) {
                permutation[l] = l + K;
                permutation[l+K] = l;
            }
        }

        for (int j = 1; j <= N; ++j)
            cout << permutation[j] << " ";
        cout << endl;
    }
    return 0;
}
