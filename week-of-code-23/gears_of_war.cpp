#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);
    i64 q;
    cin >> q;

    for (i64 i = 0; i < q; ++i) {
        i64 n;
        cin >> n;
        if (n % 2 == 0) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}