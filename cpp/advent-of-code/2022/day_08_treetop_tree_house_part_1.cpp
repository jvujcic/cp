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

    vector<vector<bool>> visible(N, vector(M, false));

    // left -> right
    for (ull i = 0; i < N; i++) {
        int max = -1;
        for (ull j = 0; j < M; j++) {
            if (grid[i][j] > max) {
                max = grid[i][j];
                visible[i][j] = true;
            }
        }
    }

    // right -> left
    for (ull i = 0; i < N; i++) {
        int max = -1;
        for (ull j = M - 1; j != 0; j--) {
            if (grid[i][j] > max) {
                max = grid[i][j];
                visible[i][j] = true;
            }
        }
    }

    // down -> up
    for (ull j = 0; j < M; j++) {
        int max = -1;
        for (ull i = 0; i < N; i++) {
            if (grid[i][j] > max) {
                max = grid[i][j];
                visible[i][j] = true;
            }
        }
    }

    // up -> down
    for (ull j = 0; j < M; j++) {
        int max = -1;
        for (ull i = N - 1; i != 0; i--) {
            if (grid[i][j] > max) {
                max = grid[i][j];
                visible[i][j] = true;
            }
        }
    }

    ull result = 0;

    for (ull i = 0; i < N; i++) {
        result += count(visible[i].begin(), visible[i].end(), true);
    }

    cout << result << endl;

    return 0;
}
