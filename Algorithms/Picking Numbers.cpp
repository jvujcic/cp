#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main() {
    // freopen("temp/input.txt", "r", stdin);

    int N;
    cin >> N;

    map<int, int> number_counts;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        auto it = number_counts.find(x);
        if (it != number_counts.end())
            it->second++;
        else
            number_counts[x] = 1;
    }

    int solution = prev(number_counts.end())->second;

    for (auto it = number_counts.begin(); it != prev(number_counts.end()); ++it) {
        if (next(it)->first - it->first == 1) {
            int size = it->second + next(it)->second;
            if (solution < size)
                solution = size;
        } else if (it->second > solution) {
            solution = it->second;
        }
    }

    cout << solution << endl;
}