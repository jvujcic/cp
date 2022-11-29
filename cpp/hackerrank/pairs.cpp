#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
    //freopen("input.txt", "r", stdin);

    LL N, K;

    cin >> N >> K;

    vector<LL> numbers(N);

    for (int i = 0; i < N; ++i)
        cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    LL solution = 0;

    for (int i = 0, j = 1; i < N - 1; ++i) {
        for (; j < N && numbers[j] - numbers[i] < K; ++j);

        if (j == N)
            break;

        if (numbers[j] - numbers[i] == K)
            ++solution;
    }

    cout << solution << endl;

    return 0;
}