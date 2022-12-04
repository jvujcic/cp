#include <bits/stdc++.h>

using namespace std;

int64_t getPriority(string rs) {
    unordered_set<char> seen;

    for (uint64_t i = 0; i < rs.length() / 2; i++) {
        seen.insert(rs[i]);
    }

    for (uint64_t i = rs.length() / 2; i < rs.length(); i++) {
        if (seen.contains(rs[i])) {
            if (isupper(rs[i]))
                return rs[i] - 'A' + 27;
            else
                return rs[i] - 'a' + 1;
        }
    }
    exit(1);
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
