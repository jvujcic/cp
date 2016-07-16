#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL mod = pow(10, 9) + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    
    int N;
    cin >> N;

    vector<LL> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    LL L, R;
    cin >> L >> R;

    vector<vector<LL>> count(R+1, vector<LL>(N));

    for (int j = 0; j < N; ++j)
        count[0][j] = 1;

    for (int i = 1; i < R + 1; ++i) {
        if (i % A[0] == 0) count[i][0] = 1;
    }

    for (int i = 1; i < R + 1; ++i) {
        for (int j = 1; j < N; ++j) {
            if (A[j] > i)
                count[i][j] = count[i][j-1];
            else
                count[i][j] = count[i][j-1] + count[i-A[j]][j];

            count[i][j] %= mod;
        }
    }


    LL solution = 0;

    for (int i = L; i < R + 1; ++i) {
        solution += count[i][N-1];
        solution %= mod;
    }

    cout << solution << endl;
}