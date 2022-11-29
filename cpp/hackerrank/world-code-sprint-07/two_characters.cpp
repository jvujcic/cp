#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    int sol = 0;

    for (char i = 'a'; i < 'z'; ++i) {
        for (char j = i+1; j <= 'z'; ++j) {
            char last = '0';
            int num = 0;
            bool ok = true;
            for (char c : s) {
                if (c == last) {
                    ok = false;
                    break;
                }
                else if (c == i || c == j) {
                    last = c;
                    ++num;
                }
            }
            if (ok && num > sol) sol = num;
        }
    }

    cout << sol << endl;
    return 0;
}