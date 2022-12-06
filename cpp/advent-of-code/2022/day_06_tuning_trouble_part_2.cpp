#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

ull marker_size = 14;

int main() {
    string input;
    ll solution;

    cin >> input;

    for (ull i = 0; i < input.length() - marker_size; ++i) {
        if (set<char>(input.begin() + i, input.begin() + i + marker_size).size() == marker_size) {
            solution = i + marker_size;
            break;
        }
    }

    cout << solution << endl;
    return 0;
}