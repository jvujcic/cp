#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef long long LL;

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        LL c_sum = 0, nc_sum = 0;
        LL c_sum_max = numeric_limits<LL>::min();

        int max_neg = numeric_limits<int>::min();
        bool found_pos = false;
        for (int j = 0; j < N ; ++j) {
            int x;
            cin >> x;
            if (x >= 0) {
                found_pos = true;
                nc_sum += x;
            }
            else if (x > max_neg)
                max_neg = x;

            c_sum += x;
            if (c_sum > c_sum_max) c_sum_max = c_sum;
            if (c_sum < 0) c_sum = 0;
        }
        if (!found_pos) nc_sum = max_neg;
        cout << c_sum_max << " " << nc_sum << endl;
    }

    return 0;
}