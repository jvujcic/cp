#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // freopen("temp/input.txt", "r", stdin);

    string firstword, secondword;
    getline(cin, firstword);
    getline(cin, secondword);

    int k;
    cin >> k;

    int max_len = min(firstword.length(), secondword.length());

    int count_same = 0;

    for (int i = 0; i < max_len; ++i) {
        if (firstword[i] != secondword[i])
            break;
        count_same++;
    }

    int min_del = firstword.length() - count_same;
    int min_add = secondword.length() - count_same;
    int min_op = min_del + min_add;

    if (k >= firstword.length() + secondword.length())
        cout << "Yes";
    else if (min_op <= k && (k - min_op) % 2 == 0)
        cout << "Yes";
    else
        cout << "No";
}