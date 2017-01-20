#include <bits/stdc++.h>

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;


struct Node {
    i64 parent, sum, sum_square, level, num_of_nodes;
    vector<i64> child;
};

void make_level(vector<Node> & tree, i64 current_node, i64 current_level) {
    tree[current_node].level = current_level;
    for (i64 v : tree[current_node].child)
        make_level(tree, v, current_level + 1);
}

void calculate(vector<Node> & tree, i64 current_node) {
    if (tree[current_node].child.empty()) {
        tree[current_node].num_of_nodes = 1;
        return;
    }

    i64 num_of_nodes = 1;
    for (i64 node : tree[current_node].child) {
        calculate(tree, node);
        num_of_nodes += tree[node].num_of_nodes;
        tree[current_node].sum += tree[node].num_of_nodes + tree[node].sum;
        tree[current_node].sum_square += tree[node].num_of_nodes + 2*tree[node].sum + tree[node].sum_square;
    }
    tree[current_node].num_of_nodes = num_of_nodes;
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

    make_level(tree, 1, 0);
    calculate(tree, 1);
    auto lca_table = make_lca_table(tree);

    i64 q;
    cin >> q;

    for (i64 i = 0; i < q; ++i) {
        i64 u, v;
        cin >> u >> v;
        i64 lca = find_lca(tree, lca_table, u, v);
        if (lca == v) {
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