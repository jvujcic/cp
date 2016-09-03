#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <iterator>
#include <sstream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int x;
    cin >> x;

    for (int i = 0; i < x; ++i) {
        int n;
        cin >> n;
        getchar();

        unordered_map<string, unordered_set<string>> order;

        bool violation = false;

        for (int j = 0; j < n; ++j) {
            if (violation)
                break;
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<string> destinations;
            while (ss.good()) {
                string dest;
                getline(ss, dest, ',');
                destinations.push_back(dest);
                if (order.count(dest) == 0) {
                    order[dest];
                }
            }


            for (unsigned int i = 0; i < destinations.size() - 1; ++i) {
                if(violation)
                    break;
                auto set_i = order[destinations[i]];
                for (unsigned int j = i + 1; j < destinations.size(); ++j) {
                    auto set_j = order[destinations[j]];
                    if (set_j.count(destinations[i]) > 0) {
                        violation = true;
                        break;
                    }
                    else {
                        set_i.insert(destinations[j]);
                        set_i.insert(set_j.begin(), set_j.end());
                    }
                }
            }
        }

        if (violation)
            cout << "ORDER VIOLATION" << endl;
        else
            cout << "ORDER EXISTS" << endl;
    }
}
