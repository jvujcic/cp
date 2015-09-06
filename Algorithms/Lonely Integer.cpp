#include <iostream>

using namespace std;

typedef long long LL;

int main() {
    //freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    LL result = 0;
    for (int i = 0; i < N; ++i) {
        LL a;
        cin >> a;
        result ^= a;
    }

    cout << result << endl;
    return 0;
}