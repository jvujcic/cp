#include <bits/stdc++.h>

using namespace std;

int64_t getPriority(string rs1, string rs2, string rs3) {
    unordered_set<char> rs1_set{rs1.begin(), rs1.end()};
    unordered_set<char> rs2_set{rs2.begin(), rs2.end()};

    for (uint64_t i = 0; i < rs3.length(); i++) {
        if (rs1_set.contains(rs3[i]) && rs2_set.contains(rs3[i])) {
            if (isupper(rs3[i]))
                return rs3[i] - 'A' + 27;
            else
                return rs3[i] - 'a' + 1;
        }
    }
    exit(1);
}

int main() {
    string rs1, rs2, rs3;

    int64_t sum = 0;

    while (getline(cin, rs1)) {
        getline(cin, rs2);
        getline(cin, rs3);
        sum += getPriority(rs1, rs2, rs3);
    }

    cout << sum << endl;
    return 0;
}
