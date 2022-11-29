#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    //freopen("input.txt","r",stdin);

    int N = 0;
    cin >> N;

    int K = 0;
    cin >> K;

    vector<long> candie(N);
    for (int i = 0; i < N; ++i)
        cin >> candie[i];

    sort(candie.begin(), candie.end());

    long solution = numeric_limits<long>::max();
    for (int i = 0; i < N - K; ++i)
        if (candie[i + K - 1] - candie[i] < solution)
            solution = candie[i + K - 1] - candie[i];

    cout << solution << endl;
}