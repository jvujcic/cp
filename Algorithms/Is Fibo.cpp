#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int main() {
//    freopen("input.txt","r",stdin);

    set<long long> fibonacci;
    long long a = 0, b = 1;

    for (int i = 0; i < 50; ++i) {
        fibonacci.insert(a);
        long long temp = a;
        a = a + b;
        b = temp;
    }

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        if (fibonacci.find(n) != fibonacci.end())
            cout << "IsFibo" << endl;
        else
            cout << "IsNotFibo"  << endl;
    }
    return 0;
}