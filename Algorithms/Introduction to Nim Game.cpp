#include <iostream>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    // freopen("temp/input.txt", "r", stdin);

    i64 g;
    cin >> g;
    for (i64 i = 0; i < g; ++i) {
        i64 n = 0, s_xored = 0;
        cin >> n;
        for (i64 j = 0; j < n; ++j) {
            i64 s;
            cin >> s;
            s_xored ^= s;
        }
        if (s_xored)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
}