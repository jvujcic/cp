#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1000000007LL;

int main() {
    freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;

    vector<ll> sequence(n + 1);

    for (ll i = 1; i <= n; ++i)
        cin >> sequence[i];


    if (sequence[1] != 0 && sequence[1] != -1) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> num_of_prime_factor(n + 1, 0);
    vector<ll> prime_factor(n + 1, 0);

    ll solution = 1;

    for (ll i = 2; i <= n; ++i) {
        for (ll j = 2 * i; j <= n; j += i) {
            if (num_of_prime_factor[i] == 0) {
                num_of_prime_factor[j]++;
                prime_factor[j] = i;
            }
            if (sequence[j] != -1) {
                if(sequence[i] == -1)
                    sequence[i] = sequence[j] % i;
                else if (sequence[i] != sequence[j] % i) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        if (num_of_prime_factor[i] == 0 && sequence[i] == -1) {
            solution = (solution * i) % mod;
        }

        if (num_of_prime_factor[i] == 1 && sequence[i] == -1) {
            solution = (solution * prime_factor[i]) % mod;
        }
    }

    cout << solution << endl;

    return 0;
}

