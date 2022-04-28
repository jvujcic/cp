#include <iostream>

using namespace std;

typedef long long LL;

int main() {
    //freopen("input.txt", "r", stdin);

    LL T = 0;
    cin >> T;

    for (LL i = 0; i < T; ++i) {
        LL N;
        cin >> N;
        if (N % 2 == 1) cout << "2" << endl;
        else if (N % 4 == 0) cout << "3" << endl;
        else cout << "4" << endl;
    }

    return 0;
}