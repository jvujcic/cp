#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    vector<bool> chars(25, true);
    int oddCounter = 0, countChars;
    bool isLenOdd = input.size() % 2;

    for (int i = 0; i < input.size(); ++i) {
        if(chars[input[i] - 'a']) {
            countChars = count(input.begin(), input.end(), input[i]);
            chars[input[i] - 'a'] = false;
            if(countChars % 2 == 1) oddCounter++;
        }
        
    }

    if(oddCounter > 1)
        cout << "NO";
    else if(oddCounter == 1 && !isLenOdd)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}