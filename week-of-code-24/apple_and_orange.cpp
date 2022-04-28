#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);
    i64 s, t, a, b, m, n;

    cin >> s >> t;
    cin >> a >> b;
    cin >> m >> n;

    i64 apple_count = 0;
    i64 orange_count = 0;

    for (i64 i = 0; i < m; ++i) {
        i64 d;
        cin >> d;
        if (a + d >= s && a + d <= t)
            ++apple_count;
    }
    for (i64 i = 0; i < n; ++i) {
        i64 d;
        cin >> d;
        if (b + d >= s && b + d <= t)
            ++orange_count;
    }

    cout << apple_count << endl;
    cout << orange_count << endl;

    return 0;
}