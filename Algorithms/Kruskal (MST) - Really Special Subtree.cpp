#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <queue>

using namespace std;

struct Edge {
    Edge() : node_1(0), node_2(0), weight(0) {
    }
    Edge(int node_1, int node_2, int weight) : node_1(node_1), node_2(node_2), weight(weight) {
    }

    int node_1;
    int node_2;
    int weight;
};

class Disjoint_set {
private:
    struct Node {
        Node() : rank(0), parent(this) {
        }

        int rank;
        Node* parent;
    };
    vector<Node> nodes;

public:
    Disjoint_set(int number_of_nodes) : nodes(number_of_nodes + 1) {
    }

    int find_set(int node) {
        Node* n = &nodes[node];
        while (n->parent != n) {
            n = n->parent;
        }
        return n - &nodes[0];
    }

    void union_sets(int node_1, int node_2) {
        Node* node_1_root = &nodes[find_set(node_1)];
        Node* node_2_root = &nodes[find_set(node_2)];
        if (node_1_root->rank > node_2_root->rank) {
            node_2_root->parent = node_1_root;
        } else if (node_1_root->rank < node_2_root->rank) {
            node_1_root->parent = node_2_root;
        } else {
            node_2_root->parent = node_1_root;
            node_1_root->rank++;
        }
    }
};

bool operator>(const Edge& edge_1, const Edge& edge_2) {
    bool return_value;
    if (edge_1.weight > edge_2.weight)
        return_value = true;
    else if (edge_1.weight == edge_2.weight
             && edge_1.node_1 + edge_1.node_2 + edge_1.weight > edge_2.node_1 + edge_2.node_2 + edge_2.weight)
        return_value = true;
    else
        return_value = false;

    return return_value;
}

void solve(int num_of_nodes, const vector<Edge>& edges) {
    int minimum_weight = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq(edges.begin(), edges.end());
    Disjoint_set node_partition(num_of_nodes);

    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if (node_partition.find_set(e.node_1) != node_partition.find_set(e.node_2)) {
            node_partition.union_sets(e.node_1, e.node_2);
            minimum_weight += e.weight;
        }
    }

    cout << minimum_weight << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    int num_of_nodes;
    int num_of_edges;
    cin >> num_of_nodes >> num_of_edges;

    vector<Edge> edges(num_of_edges);

    for (int i = 0; i < num_of_edges; i++) {
        int node_1, node_2, weight;
        cin >> node_1 >> node_2 >> weight;
        edges[i] = Edge(node_1, node_2, weight);
    }

    int start_node;
    cin >> start_node;

    solve(num_of_nodes, edges);

    return 0;
}
