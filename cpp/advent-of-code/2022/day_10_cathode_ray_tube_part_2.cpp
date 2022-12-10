#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

void set_pixel(ll& cycle, ll& X, vector<string>& screen) {
    ll x = (cycle - 1) % 40;
    if (x == X - 1 || x == X || x == X + 1) {
        screen[(cycle - 1) / 40][(cycle - 1) % 40] = '#';
    }
    cycle++;
}

int main() {
    string line;

    ll X = 1;
    ll cycle = 1;

    vector<string> screen(6, string(40, '.'));

    while (getline(cin, line)) {
        if (line == "noop") {
            set_pixel(cycle, X, screen);
        } else {
            set_pixel(cycle, X, screen);
            set_pixel(cycle, X, screen);

            ll a;
            sscanf(line.c_str(), "addx %lld", &a);
            X += a;
        }
    }

    for (string& row : screen) {
        cout << row << endl;
    }
    return 0;
}