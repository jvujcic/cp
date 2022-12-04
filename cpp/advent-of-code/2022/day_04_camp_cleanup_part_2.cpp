#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

int main() {
    ull x1, x2, y1, y2, sol = 0;
    string line;

    while (getline(cin, line)) {
        sscanf(line.c_str(), "%llu-%llu,%llu-%llu", &x1, &x2, &y1, &y2);
        if (!(x2 < y1 || y2 < x1))
            sol++;
    }
    cout << sol << endl;
    return 0;
}
