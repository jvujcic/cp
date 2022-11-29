#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;
using ll = long long;

const ll june_15 = 1465948800LL;
const ll july_15 = 1468540800LL;

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;

    cin >> n >> m;

    vector<string> passions(n);
    map<string, vector<int>> rating;

    for (int i = 0; i < n; i++) {
        string passion;
        cin >> passion;
        rating[passion] = vector<int>(1001);
        passions[i] = passion;
    }

    for (int i = 0; i < m; i++) {
        int id;
        ll timestamp;
        cin >> id >> timestamp;
        getchar();

        string text;
        getline(cin, text);

        int points = 0;

        if (timestamp >= june_15 && timestamp < july_15) 
            points += 20;
        else
            points += 10;

        if (text.size() < 100)
            points += 10;
        else
            points += 20;

        for (auto it = rating.begin(); it != rating.end(); ++it) {
            string passion = it->first;
            if (text.find(it->first) != string::npos) {
                it->second[id] += points;
            }
        }

    }

    for (int i = 0; i < n; i++) {
        auto it = max_element(rating[passions[i]].begin(), rating[passions[i]].end());
        if (*it == 0)
            cout << -1 << endl;
        else
            cout << it - rating[passions[i]].begin() << endl;
    }
}
