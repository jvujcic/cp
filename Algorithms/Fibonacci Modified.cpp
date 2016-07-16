#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print_solution(__int128 n) {
    string S;
    while (n != 0) {
        int digit = n%10;
        n /= 10;
        S+=to_string(digit);
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
}

int main() {
    freopen("input.txt", "r", stdin);

    int a, b, N;
    __int128 A, B;

    cin >> a >> b >> N;
    A = a; B = b;

    for (int i = 0; i < N - 2; ++i) {
        __int128 tmp = B;
        B = B*B + A;
        A = tmp;
    }

    print_solution(B);

    return 0;
}