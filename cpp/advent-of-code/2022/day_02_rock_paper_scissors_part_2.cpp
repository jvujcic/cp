#include <bits/stdc++.h>

using namespace std;

// rock = 1
// paper = 2
// scissors = 3
enum Sign { rock, paper, scissors };

// (you, opponent) -> points
map<tuple<char, Sign>, int64_t> points = {
        {{'X', rock}, 3},      // scissors
        {{'X', paper}, 1},     // rock
        {{'X', scissors}, 2},  // paper
        {{'Y', rock}, 4},      // rock
        {{'Y', paper}, 5},     // paper
        {{'Y', scissors}, 6},  // scissors
        {{'Z', rock}, 8},      // paper
        {{'Z', paper}, 9},     // scissors
        {{'Z', scissors}, 7},  // rock
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
        Sign op = mapCharToSign(c1);
        result += points[{c2, op}];
    }

    cout << result << endl;
    return 0;
}
