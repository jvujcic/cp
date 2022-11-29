#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve(string word) {
    pair<int, int> solution = { -1, -1 };

    for (int j = word.size() - 1; j >= 0; --j)
        for (int i = j; i >= 0; --i)
            if (word[i] < word[j] && i > solution.first) solution = { i, j };

    if (solution.first == solution.second)
        cout << "no answer" << endl;
    else {
        swap(word[solution.first], word[solution.second]);
        sort(word.begin() + solution.first + 1, word.end(), less<int>());
        cout << word << endl;
    }
}


int main() {
   // freopen("input.txt","r",stdin);

    int numberOfTestCases;
    cin >> numberOfTestCases;

    for (int i = 0; i < numberOfTestCases; ++i) {
        string word;
        cin >> word;
        solve(word);
    }
    return 0;
}