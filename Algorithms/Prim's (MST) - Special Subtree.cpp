#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>

using namespace std;

void solve(int num_of_nodes, int start_node, const vector<list<pair<int, int>>>& edges) {
    int total_weight = 0;

    vector<int> C(num_of_nodes + 1, 100001);
    vector<bool> Q(num_of_nodes + 1, false);

    Q[0] = true;
    C[start_node] = 0;

    while (!accumulate(Q.begin(), Q.end(), true, logical_and<bool>())) {
        auto c_it = min_element(C.begin(), C.end());
        int current_node = distance(C.begin(), c_it);
        total_weight += *c_it;
        *c_it = 100001;
        Q[current_node] = true;
        for (auto node : edges[current_node]) {
            if (!Q[node.first] && node.second < C[node.first]) {
                C[node.first] = node.second;
            }
        }
    }

    cout << total_weight << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int num_of_nodes;
    int num_of_edges;
    cin >> num_of_nodes >> num_of_edges;

    vector<list<pair<int, int>>> edges(num_of_nodes + 1);

    for (int i = 0; i < num_of_edges; i++) {
        int node_1, node_2, length;
        cin >> node_1 >> node_2 >> length;
        edges[node_1].push_back(make_pair(node_2, length));
        edges[node_2].push_back(make_pair(node_1, length));
    }

    int start_node;
    cin >> start_node;

    solve(num_of_nodes, start_node, edges);
    return 0;
}
