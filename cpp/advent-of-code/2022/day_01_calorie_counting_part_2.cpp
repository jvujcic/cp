#include <bits/stdc++.h>
#include <ranges>

using namespace std;

int main() {
    string line;
    int64_t sum = 0;
    vector<int64_t> totals;

    while (getline(std::cin, line)) {
        if (line.size() != 0) {
            int64_t n = stoll(line);
            sum += n;
        } else {
            totals.push_back(sum);
            sum = 0;
        }
    }
    totals.push_back(sum);

    sort(totals.begin(), totals.end(), greater<int>());
    int64_t solution = accumulate(totals.begin(), totals.begin() + 3, 0LL);

    cout << solution << endl;
    return 0;
}
