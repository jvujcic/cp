#include <bits/stdc++.h>

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

    int64_t solution = *max_element(totals.begin(), totals.end());

    cout << solution << endl;
    return 0;
}
