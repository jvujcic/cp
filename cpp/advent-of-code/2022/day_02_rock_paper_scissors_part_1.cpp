#include <bits/stdc++.h>

using namespace std;

// rock = 1
// paper = 2
// scissors = 3
enum Sign { rock, paper, scissors };

// (you, opponent) -> points
map<tuple<Sign, Sign>, int64_t> points = {
        {{rock, rock}, 4},
        {{rock, scissors}, 7},
        {{rock, paper}, 1},
        {{paper, paper}, 5},
        {{paper, rock}, 8},
        {{paper, scissors}, 2},
        {{scissors, scissors}, 6},
        {{scissors, paper}, 9},
        {{scissors, rock}, 3},
};

Sign mapCharToSign(char c) {
    switch (c) {
        case 'A':
        case 'X':
            return rock;
        case 'B':
        case 'Y':
            return paper;
        case 'C':
        case 'Z':
            return scissors;
        default:
            exit(1);
    }
}

int main() {
    char c1, c2;

    int64_t result = 0;

    while (cin >> c1 >> c2) {
        auto you = mapCharToSign(c2);
        auto op = mapCharToSign(c1);
        result += points[{you, op}];
    }

    cout << result << endl;
    return 0;
}
