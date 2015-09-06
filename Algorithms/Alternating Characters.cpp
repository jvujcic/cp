#include <iostream>
#include <string>

using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        int numOfDeletions = 0;
        for (int j = 0; j < str.length() - 1; ++j) {
            if (str[j] == str[j + 1]) ++numOfDeletions;
        }
        cout << numOfDeletions << endl;
    }

    return 0;
}