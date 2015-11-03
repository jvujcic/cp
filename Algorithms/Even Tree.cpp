#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <memory>
#include <set>

using namespace std;

struct Node {
    Node(int node_id) : node_id(node_id) {
    }
    int node_id;
    shared_ptr<Node> parent;
    list<shared_ptr<Node>> children;
    int weight;
};

void make_tree(shared_ptr<Node> root, const vector<list<int>>& tree) {
    queue<shared_ptr<Node>> q;
    set<int> usedNodes;

    q.push(root);
    usedNodes.insert(1);

    while (!q.empty()) {
        shared_ptr<Node> n_ptr = q.front();
        q.pop();
        for (int node : tree[n_ptr->node_id]) {
            shared_ptr<Node> tmp = make_shared<Node>(node);
            if (usedNodes.count(tmp->node_id) == 0) {
                tmp->parent = n_ptr;
                tmp->node_id = node;
                n_ptr->children.push_back(tmp);
                q.push(tmp);
                usedNodes.insert(tmp->node_id);
            }
        }
    }
}

int calcualate_node_weights(shared_ptr<Node> root) {
    int weight = 1;
    if (!root->children.empty()) {
        for (auto n_ptr : root->children) {
            weight += calcualate_node_weights(n_ptr);
        }
    }

    root->weight = weight;
    return weight;
}

int remove_edges(shared_ptr<Node> root) {
    if (root->children.empty())
        return 0;

    int removed_edges = 0;
    for (auto n_ptr : root->children) {
        if (n_ptr->weight % 2 == 0) {
            removed_edges++;
        }
        removed_edges += remove_edges(n_ptr);
    }

    return removed_edges;
}

void solve(int num_of_nodes, vector<list<int>> tree) {

    shared_ptr<Node> root = make_shared<Node>(1);
    make_tree(root, tree);

    calcualate_node_weights(root);
    int solution = remove_edges(root);
    cout << solution << endl;
}

int main() {
    freopen("input.txt", "r", stdin);

    int num_of_nodes;
    int num_of_edges;
    cin >> num_of_nodes >> num_of_edges;

    vector<list<int>> tree(num_of_nodes + 1);

    for (int i = 0; i < num_of_edges; i++) {
        int node_1, node_2;
        cin >> node_1 >> node_2;
        tree[node_1].push_back(node_2);
        tree[node_2].push_back(node_1);
    }

    solve(num_of_nodes, tree);

    return 0;
}
