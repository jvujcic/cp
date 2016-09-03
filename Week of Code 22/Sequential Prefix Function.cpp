#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const size_t SIZE = 200001;

int main() {
    freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;

    vector<ll> sequence;
    vector<ll> suffix_len;
    vector<ll> solution;

    sequence.reserve(SIZE);
    suffix_len.reserve(SIZE);
    solution.reserve(SIZE);

    ll len;

    for (ll i = 0; i < n; ++i) {
        string op;
        cin >> op;
        if (op == "+") {
            ll x;
            cin >> x;
            sequence.push_back(x);
            if (sequence.size() == 1) {
                len = 0;
                suffix_len.push_back(0);
            }
            else if (sequence.size() > 1) {
                while (true) {
                    if (sequence.back() == sequence[len]) {
                        suffix_len.push_back(++len);
                        break;
                    }
                    else if (len != 0) {
                        len = suffix_len[len - 1];
                    }
                    else {
                        suffix_len.push_back(0);
                        break;
                    }
                }
            }
        }
        else {
            sequence.pop_back();
            suffix_len.pop_back();
            len = suffix_len.back();
        }

        if (sequence.size() == 0)
            // cout << 0 << endl;
            // printf("0\n");
            solution.push_back(0);
        else
            // cout  << suffix_len.back() << endl;
            // printf("%lld\n", suffix_len.back());
            solution.push_back(suffix_len.back());
    }

    for (ll x : solution)
        cout << x << endl;

    return 0;
}
