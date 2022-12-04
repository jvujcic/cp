#include <bits/stdc++.h>

using namespace std;

int64_t getPriority(string rs) {
    auto half_it = rs.begin() + (rs.end() - rs.begin()) / 2;
    auto fst_half = set<char>{rs.begin(), half_it};
    auto snd_half = set<char>{half_it, rs.end()};
    std::vector<char> intersect;

    set_intersection(fst_half.begin(), fst_half.end(), snd_half.begin(), snd_half.end(), back_inserter(intersect));
    char c = intersect.front();

    if (isupper(c))
        return c - 'A' + 27;
    else
        return c - 'a' + 1;
}

int main() {
    string rs;

    int64_t sum = 0;

    while (getline(std::cin, rs)) {
        sum += getPriority(rs);
    }

    cout << sum << endl;
    return 0;
}
