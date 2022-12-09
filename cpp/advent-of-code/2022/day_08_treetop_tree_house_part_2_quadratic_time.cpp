#include <bits/stdc++.h>

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

    vector<vector<ll>> score(N, vector(M, 1LL));

    // left -> right
    for (ull i = 0; i < N; i++) {
        vector<ull> height_index(10, 0);
        for (ull j = 0; j < M; j++) {
            int height = grid[i][j];
            ull blocking_tree_index = *max_element(height_index.begin() + height, height_index.end());
            score[i][j] *= (j - blocking_tree_index);
            height_index[height] = j;
        }
    }

    // right -> left
    for (ull i = 0; i < N; i++) {
        vector<ull> height_index(10, M - 1);
        for (ull j = M - 1; j != 0; j--) {
            int height = grid[i][j];
            ull blocking_tree_index = *min_element(height_index.begin() + height, height_index.end());
            score[i][j] *= (blocking_tree_index - j);
            height_index[height] = j;
        }
    }

    // down -> up
    for (ull j = 0; j < M; j++) {
        vector<ull> height_index(10, 0);
        for (ull i = 0; i < N; i++) {
            int height = grid[i][j];
            ull blocking_tree_index = *max_element(height_index.begin() + height, height_index.end());
            score[i][j] *= (i - blocking_tree_index);
            height_index[height] = i;
        }
    }

    // up -> down
    for (ull j = 0; j < M; j++) {
        vector<ull> height_index(10, N - 1);
        for (ull i = N - 1; i != 0; i--) {
            int height = grid[i][j];
            ull blocking_tree_index = *min_element(height_index.begin() + height, height_index.end());
            score[i][j] *= (blocking_tree_index - i);
            height_index[height] = i;
        }
    }

    auto score_flat = score | ranges::views::join;
    cout << *ranges::max_element(score_flat.begin(), score_flat.end()) << endl;

    return 0;
}
