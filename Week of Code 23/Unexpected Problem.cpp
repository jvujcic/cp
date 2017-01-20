#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

const i64 mod = 1000000007LL;

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);
    string str;
    cin >> str;

    i64 m;
    cin >> m;

    vector<i64> lps(str.size());
    i64 len = 0;
    lps[0] = 0;
    i64 i = 1;

    while(i < str.size()) {
        if (str[i] == str[len])
            lps[i++] = ++len;
        else if (len != 0)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }

    i64 period = str.size() - lps[str.size() - 1];
    if (str.size() % period != 0) 
        period = str.size();

    i64 solution = (m / period) % mod;

    cout << solution << endl;

    return 0;
}