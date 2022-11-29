#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
    freopen("input.txt", "r", stdin);

    LL T;
    cin >> T;

    for (LL i = 0; i < T; ++i) {
        LL M, N;
        cin >> M >> N;
        vector<LL> prices(N);
        for (LL j = 0; j < N; ++j)
            cin >> prices[j];
        for (LL j = 0; j < N - 1; ++j)
            for (LL k = j + 1; k < N; ++k)
                if ((prices[j] + prices[k]) == M)
                    cout << j + 1 << " " << k + 1<< endl;
    }

    return 0;
}