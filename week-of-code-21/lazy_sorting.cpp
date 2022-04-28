#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

typedef long long LL;

LL factorial(LL n) {
    LL fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    vector<int> p(101);

    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        p[n]++;
    }

    LL num_perm = factorial(N);

    for (int m : p) {
        if (m > 0) {
            LL fact = factorial(m);
            num_perm /= fact;
        }
    }

    cout << num_perm << ".000000" << endl;
}