#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll num_of_subtrees_with_root(vector<set<ll>> & tree, ll root, set<ll> & removed_vertex) {
    removed_vertex.insert(root);

    ll result = 1;

    for (ll v : tree[root]) {
        if (removed_vertex.count(v) == 0)
            result *= (num_of_subtrees_with_root(tree, v, removed_vertex) + 1);
    }

    removed_vertex.erase(root);

    return result;
}

ll num_of_subtrees(vector<set<ll>> & tree) {
    ll result = 0;
    set<ll> removed_vertex;

    for (ull v = 1; v < tree.size(); ++v) {
        result += num_of_subtrees_with_root(tree, v, removed_vertex);
        removed_vertex.insert(v);
    }

    return result;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> weights(n + 1);
    ll sum_of_weights = 0;

    for (ll i = 1; i <= n; ++i) {
        cin >> weights[i];
        sum_of_weights += weights[i];
    }

    vector<ll> values(sum_of_weights + 1);

    for (ll i = 0; i <= sum_of_weights; ++i) {
        cin >> values[i];
    }

    vector<set<ll>> tree(n + 1);

    for (ll i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].insert(v);
        tree[v].insert(u);
    }

    ll sum = 0;

    for (ull v = 1; v < tree.size(); ++v) {
        set<ll> removed_vertex;
        sum += weights[v] * num_of_subtrees_with_root(tree, v, removed_vertex);
    }

    cout << double(sum) / num_of_subtrees(tree) << endl;

}

int main() {
    freopen("input.txt", "r", stdin);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }
    return 0;
}
