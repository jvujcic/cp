#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

int main() {
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 2 << endl;
        return 0;
    }
    else if (n == 2) {
        int x, y;
        cin >> x >> y;
        if (x == y)
            cout << 2 << endl;
        else
            cout << 1 << endl;
        return 0;
    }

    vector<int> sticks(n);

    for (int i = 0; i < n; ++i) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    int sum = accumulate(sticks.begin(), sticks.end() - 1, 0);

    if (sticks.back() < sum) {
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
    }

    return 0;
}
