#include <iostream>

using namespace std;

int maxChocolate(int N, int C, int M) {
    int result = N / C;
    int numberOfWrappers = result;
    while(numberOfWrappers >= M) {
        int newChocolate =  numberOfWrappers / M;
        result += newChocolate;
        numberOfWrappers = numberOfWrappers - newChocolate*M + newChocolate;
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N, C, M;
        cin >> N >> C >> M;
        cout << maxChocolate(N, C, M) << endl;
    }

    return 0;
}