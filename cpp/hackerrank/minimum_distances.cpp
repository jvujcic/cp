#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Number {
    int val, index;

    bool operator<(const Number & n) {
        if (val < n.val)
            return true;
        else if (val == n.val)
            return index < n.index;
        else
            return false;
    }
};

int main() {
    freopen("input.txt", "r", stdin);

    int n;

    cin >> n;
    vector<Number> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i].val;
        numbers[i].index = i;
    }

    sort(numbers.begin(), numbers.end());

    int min_distance = -1;

    for (int i = 0; i < n - 1; ++i) {
        if (numbers[i].val == numbers[i + 1].val) {
            int dist = numbers[i + 1].index - numbers[i].index;
            if (min_distance == -1)
                min_distance = dist;
            else if (min_distance > dist)
                min_distance = dist;
        }
    }

    cout << min_distance << endl;

    return 0;
}