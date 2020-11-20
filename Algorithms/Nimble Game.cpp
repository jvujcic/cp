#include <iostream>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    freopen("temp/input.txt", "r", stdin);

    i64 T;
    cin >> T;
    for (i64 i = 0; i < T; ++i) {
        i64 n, xored = 0;
        cin >> n;
        for (i64 j = 0; j < n; ++j) {
            i64 c;
            cin >> c;
            if (j == 0)
                continue;
            if (c % 2 != 0)
                xored ^= j;
        }
        if (xored)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
}