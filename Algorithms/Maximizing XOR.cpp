#include <iostream>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;

    int max = -1;

    for(int i = l; i <= r; i++)
        for (int j = i; j <= r; j++) {
            int xorRes = i ^ j;
            if (xorRes > max) max = i^j;
        }

    cout << max;
    return 0;
}