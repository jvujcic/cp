#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
typedef long long LL;

int main() {
    // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    vector<int> rating(N);
    vector<LL> candies(N, 1);

    for (int i = 0; i < N; i++) {
        cin >> rating[i];
    }

    bool change = true;

    while (change) {
        change = false;
        if (rating[0] > rating [1] && candies[0] <= candies[1]) {
            candies[0] = candies[1] + 1;
            change = true;
        }
        for(int i = 1; i < N - 1; i++) {
            if (rating[i] > rating[i-1] && candies[i] <= candies[i-1])  {
                candies[i] = candies[i-1] + 1;
                change = true;
            }
            if (rating[i] > rating[i+1] && candies[i] <= candies[i+1]) {
                candies[i] = candies[i+1] + 1;
                change = true;
            }
        }
        if (rating[N-1] > rating[N-2] && candies[N-1] <= candies[N-2]) {
            candies[N-1] = candies[N-2] + 1;
            change = true;
        }
    }

    LL sum = accumulate(candies.begin(), candies.end(), 0LL);
    cout << sum << endl;
    return 0;
}