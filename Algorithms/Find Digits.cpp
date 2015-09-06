#include <iostream>
#include <string>

using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        string stringN = to_string(N);
        int numPositions = 0;
        for(int i = 0; i < stringN.size(); ++i)
            if(stringN[i] != '0' && N % (stringN[i] - '0') == 0)
                numPositions++;
        cout << numPositions << endl;
    }
    return 0;
}