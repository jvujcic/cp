#include <bits/stdc++.h>

using namespace std;

int64_t getPriority(string rs1, string rs2, string rs3) {
    unordered_set<char> seen1, seen2;

    for (uint64_t i = 0; i < rs1.length(); i++) {
        seen1.insert(rs1[i]);
    }
    for (uint64_t i = 0; i < rs2.length(); i++) {
        seen2.insert(rs2[i]);
    }
    for (uint64_t i = 0; i < rs3.length(); i++) {
        if (seen1.contains(rs3[i]) && seen2.contains(rs3[i])) {
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
