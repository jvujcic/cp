#include <iostream>
#include <string>

using namespace std;

int main() {
   // freopen("input.txt","r",stdin);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int numberOfFives = -1;
        for (int i = N; i >= 0; i--)
            if (i % 3 == 0 && (N-i) % 5 == 0) {
                numberOfFives = i;
                break;
            }
        if (numberOfFives != -1) {
            string S = string(numberOfFives, '5') + string(N - numberOfFives, '3');
            cout << S << endl;
        }
        else
            cout << "-1" << endl;
    }

    return 0;
}