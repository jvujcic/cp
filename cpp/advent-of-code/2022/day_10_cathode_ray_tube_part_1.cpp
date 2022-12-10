#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

int main() {
    string line;

    ll X = 1;
    ll cycle = 0;
    ll next_cycle = 20;
    ll solution = 0;

    while (getline(cin, line)) {
        if (line == "noop") {
            cycle++;
            if (cycle >= next_cycle) {
                solution += (next_cycle * X);
                next_cycle += 40;
            }
        } else {
            cycle += 2;
            if (cycle >= next_cycle) {
                solution += (next_cycle * X);
                next_cycle += 40;
            }
            ll a;
            sscanf(line.c_str(), "addx %lld", &a);
            X += a;
        }
    }

    cout << solution << endl;
    return 0;
}