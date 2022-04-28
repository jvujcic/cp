#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;

    vector<ll> X(n), Y(n);

    for (ll i = 0; i < n; ++i)
        cin >> X[i];

    for (ll i = 0; i < n; ++i)
        cin >> Y[i];

    ll sum_of_X = accumulate(X.begin(), X.end(), 0LL);
    ll sum_of_Y = accumulate(Y.begin(), Y.end(), 0LL);

    if (sum_of_X != sum_of_Y) {
        cout << -1 << endl;
        return 0;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll solution = 0;

    for (ll i = 0; i < n; ++i) {
        if (X[i] > Y[i])
            solution += (X[i] - Y[i]);
    }

    cout << solution << endl;

    return 0;
}
