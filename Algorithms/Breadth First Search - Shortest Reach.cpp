#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void solve(int num_of_nodes, int start_node, const vector<list<int>>& edges) {
    vector<int> length_to_nodes(num_of_nodes + 1, -1);
    queue<int> q;
    length_to_nodes[start_node] = 0;
    q.push(start_node);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();
        for (auto node : edges[current_node]) {
            if (length_to_nodes[node] == -1) {
                length_to_nodes[node] = length_to_nodes[current_node] + 6;
                q.push(node);
            }
        }
    }

    for (int i = 1; i < length_to_nodes.size(); i++) {
        if (length_to_nodes[i] != 0)
            cout << length_to_nodes[i] << " ";
    }
    cout << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int num_of_tests;
    cin >> num_of_tests;

    for (int i = 0; i < num_of_tests; i++) {
        int num_of_nodes, num_of_edges;
        cin >> num_of_nodes;
        cin >> num_of_edges;
        vector<list<int>> edges(num_of_nodes + 1);
        for (int j = 0; j < num_of_edges; j++) {
            int node_1, node_2;
            cin >> node_1 >> node_2;
            edges[node_1].push_back(node_2);
            edges[node_2].push_back(node_1);
        }

        int start_node;
        cin >> start_node;
        solve(num_of_nodes, start_node, edges);
    }

    return 0;
}
