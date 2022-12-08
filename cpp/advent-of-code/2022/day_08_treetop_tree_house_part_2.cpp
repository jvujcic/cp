#include <bits/stdc++.h>
#include <ranges>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

int main() {

    string line;
    vector<string> input;
    while (cin >> line) {
        input.push_back(line);
    }

    ull N = input.size();
    ull M = input.front().size();

    vector<vector<int>> grid(N, vector<int>(N));

    for (ull i = 0; i < N; i++) {
        for (ull j = 0; j < M; j++) {
            grid[i][j] = input[i][j] - '0';
        }
    }

    vector<vector<ll>> score(N, vector(M, 0LL));

    for (ull i = 1; i < N - 1; i++) {
        for (ull j = 1; j < M - 1; j++) {
            int current_height = grid[i][j];
            ll& current_score = score[i][j];
            current_score = 1;
            ll k = 1;
            while (j - k > 0 && grid[i][j - k] < current_height)
                k++;
            current_score *= k;

            k = 1;
            while (j + k < M - 1 && grid[i][j + k] < current_height)
                k++;
            current_score *= k;

            k = 1;
            while (i - k > 0 && grid[i - k][j] < current_height)
                k++;
            current_score *= k;

            k = 1;
            while (i + k < N - 1 && grid[i + k][j] < current_height)
                k++;
            current_score *= k;
        }
    }

    auto score_flat = score | ranges::views::join;
    cout << *ranges::max_element(score_flat.begin(), score_flat.end()) << endl;
    return 0;
}