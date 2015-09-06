#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0)  {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void searchForSubset(vector<int> &numbers) {
    for (unsigned int i = 0; i < numbers.size(); ++i) 
        for (unsigned int j = i; j < numbers.size(); ++j) 
            if (gcd(numbers[i], numbers[j]) == 1) {
                cout << "YES" << endl;
                return;
            }
    cout << "NO" << endl;
    return;
}

int main() {
    //freopen("input.txt","r",stdin);

    int T;
    cin >> T;
    
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        vector<int> numbers(N);
        for (int j = 0; j < N; ++j)
            cin >> numbers[j];
        searchForSubset(numbers);
    }

    return 0;
}