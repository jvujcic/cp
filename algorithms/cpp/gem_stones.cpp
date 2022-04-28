#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> rocks;
    rocks.reserve(N);

    while(N--) {
        string S;
        cin >> S;
        rocks.push_back(S);
    }

    int result = 0;

    for(int i = 'a'; i <= 'z'; i++) {
        bool found = true;
        for(int j = 0; j < rocks.size(); j++)
            if(rocks[j].find(i) == string::npos) {
                found = false;
                break;
            }
        if(found) result++;
    }

    cout << result;
    return 0;
}