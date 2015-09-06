#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    multiset<int> sticks;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sticks.insert(x);
    }

    while (!sticks.empty()) {
        cout << sticks.size() << endl;
        sticks.erase(*sticks.begin());
    }

    return 0;
}