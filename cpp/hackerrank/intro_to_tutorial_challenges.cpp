#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);

    int V, n;
    cin >> V >> n;

    vector<int> ar(n);
    for (int i = 0; i < n; ++i)
        cin >> ar[i];

    auto it = lower_bound(ar.begin(), ar.end(), V);
    cout << it - ar.begin() << endl;
}