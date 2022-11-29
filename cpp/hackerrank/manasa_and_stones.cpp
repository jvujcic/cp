#include <iostream>
#include <set>

using namespace std;

set<int> stones(int n, int a, int b) {
    set<int> result;
    for(int i = 0; i < n; i++) {
        int lastStone = i*a + (n-1-i)*b;
        result.insert(lastStone);
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, a, b;
        cin >> n >> a >> b;
        auto S = stones(n, a, b);
        for(auto i: S) cout << i << " ";
        cout << endl;
    }
    return 0;
}
