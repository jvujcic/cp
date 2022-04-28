#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int x1, v1, x2, v2;

    cin >> x1 >> v1 >> x2 >> v2;

    if (v1 == v2) {
        if (x1 == x2) cout << "YES";
        else cout << "NO";
        return 0;
    }

    int k;
    k = (x2 - x1) / (v1 - v2);

    if (k >= 0 && x1 + v1*k == x2 + v2*k) cout << "YES";
    else cout << "NO";

    return 0;
}