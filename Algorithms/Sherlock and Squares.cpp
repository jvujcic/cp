#include <iostream>
#include <cmath>

using namespace std;

void solve(long long A, long long B) {
    long long x = sqrt(A);
    long long y = sqrt(B);
    x = (x*x == A ? x : x + 1);
    y = ((y+1)*(y+1) == B ? y + 1 : y);
    long long solution = (y - x + 1 >= 0 ? y - x + 1 : 0);
    cout << solution << endl;
}

int main() {
    //freopen("input.txt","r",stdin);

    int numberOfTestCases;
    cin >> numberOfTestCases;

    for (int i = 0; i < numberOfTestCases; ++i) {
        long long A, B;
        cin >> A >> B;
        solve(A, B);
    }
}