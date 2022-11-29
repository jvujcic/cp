#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

struct Node {
    i64 parent, sum, sum_square, level, num_of_nodes;
    vector<i64> child;
};

void make_level(vector<Node> & tree) {
    queue<i64> q;
    q.push(1);
    tree[1].level = 0;

    while (!q.empty()) {
        i64 node = q.front();
        q.pop();
        for (i64 v : tree[node].child) {
            tree[v].level = tree[node].level + 1;
            q.push(v);
        }
    }
}

void calculate(vector<Node> & tree) {
    vector<i64> nodes;
    nodes.reserve(tree.size() - 1);
    nodes.push_back(1);

    for(int i = 0; i < nodes.size(); ++i) {
        for(i64 v : tree[nodes[i]].child)
            nodes.push_back(v);
    }

    i64 num_of_nodes = 1;
    for (i64 i = nodes.size() - 1; i >= 0; --i) {
        if (tree[nodes[i]].child.empty())
            tree[nodes[i]].num_of_nodes = 1;
        else {
            i64 num_of_nodes = 1;
            for (i64 v : tree[nodes[i]].child) {
                num_of_nodes += tree[v].num_of_nodes;
                tree[nodes[i]].sum += tree[v].num_of_nodes + tree[v].sum;
                tree[nodes[i]].sum_square += tree[v].num_of_nodes + 2*tree[v].sum + tree[v].sum_square;
            }
            tree[nodes[i]].num_of_nodes = num_of_nodes;
        }
    }
}

vector<vector<i64>> make_lca_table(const vector<Node> & tree) {
    i64 max_log = log2(tree.size() - 1);
    vector<vector<i64>> lca_table(tree.size(), vector<i64>(max_log + 1, -1));

    for (i64 i = 1; i < tree.size(); ++i)
        lca_table[i][0] = tree[i].parent;

    for (i64 j = 1; j <= max_log; ++j)
        for (i64 i = 1; i < tree.size(); ++i)
            if (lca_table[i][j - 1] != -1)
                lca_table[i][j] = lca_table[lca_table[i][j-1]][j-1];

    return lca_table;
}

i64 find_lca(const vector<Node> & tree, const vector<vector<i64>> & lca_table, i64 u, i64 v) {
    if (tree[u].level < tree[v].level)
        swap(u, v);

    i64 dist = tree[u].level - tree[v].level;

    while (dist > 0) {
        i64 up = log2(dist);
        u = lca_table[u][up];
        dist -= (1 << up);
    }

    if (u == v) return u;

    i64 max_log = log2(tree.size() - 1);

    for (i64 j = max_log; j >= 0; --j)
        if (lca_table[u][j] != -1 && lca_table[u][j] != lca_table[v][j]) {
            u = lca_table[u][j];
            v = lca_table[v][j];
        }

    return tree[u].parent;
}

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);

    i64 n;
    cin >> n;

    vector<Node> tree(n + 1);
    tree[1].parent = -1;

    for (i64 i = 2; i <= n; ++i) {
        i64 v;
        cin >> v;
        tree[i].parent = v;
        tree[v].child.push_back(i);
    }

    make_level(tree);
    calculate(tree);
    auto lca_table = make_lca_table(tree);

    i64 q;
    cin >> q;

    for (i64 i = 0; i < q; ++i) {
        i64 u, v;
        cin >> u >> v;
        i64 lca = find_lca(tree, lca_table, u, v);
        if (u == v) {
            cout << tree[u].sum_square << "\n";
        }
        else if (lca == v) {
            i64 dist = 1;
            i64 solution = tree[u].sum_square;
            do {
                i64 p = tree[u].parent;
                solution += dist * dist * (tree[p].num_of_nodes - tree[u].num_of_nodes)
                            + 2 * dist * (tree[p].sum - tree[u].num_of_nodes - tree[u].sum)
                            + tree[p].sum_square - tree[u].num_of_nodes - 2 * tree[u].sum - tree[u].sum_square;
                ++dist;
                u = p;
            } while (u != lca);

            cout << solution << "\n";
        }
        else {
            i64 dist = tree[u].level + tree[v].level  - 2 * tree[lca].level;
            i64 solution = dist * dist * tree[v].num_of_nodes + 2 * dist * tree[v].sum + tree[v].sum_square;
            cout << solution << "\n";
        }
    }

    return 0;
}