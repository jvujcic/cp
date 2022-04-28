#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int result = 0;
        string S;
        cin >> S;
        for(int i = 0; i < S.size()/2; i++)
            result += abs(S[i] - S[S.size()-1-i]);
        cout << result << endl;
    }
    return 0;
}
