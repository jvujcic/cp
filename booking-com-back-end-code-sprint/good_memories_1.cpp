#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <iterator>
#include <sstream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

void dfs(unordered_map<string, unordered_set<string>> & graph, string s, unordered_set<string> & marked,
        unordered_set<string> & temp_marked, bool & cycle) {
    cout << s << endl;
    if (cycle)
        return;
    if(temp_marked.count(s) > 0) {
        cycle = true;
        return;
    }
    if (marked.count(s) > 0) {
        temp_marked.insert(s);
        for(auto dest : graph[s])
            dfs(graph, dest, marked, temp_marked, cycle);
    }
    temp_marked.erase(s);
    marked.erase(s);
}


int main() {
    freopen("input.txt", "r", stdin);

    int x;
    cin >> x;

    for (int i = 0; i < x; ++i) {
        int n;
        cin >> n;
        getchar();

        unordered_map<string, int> destinations;
        unordered_map<string, unordered_set<string>> graph;

        for (int j = 0; j < n; ++j) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            string prev;
            while (ss.good()) {
                string dest;
                getline(ss, dest, ',');
                if (graph.count(dest) == 0) {
                    graph[dest];
                }
                if (prev.empty())
                    prev = dest;
                else {
                    graph[prev].insert(dest);
                    prev = dest;
                }
            }

        }

        unordered_set<string> marked;
        unordered_set<string> temp_marked;
        for (auto const & p : graph)
            marked.insert(p.first);

        bool cycle = false;

        while(!marked.empty() && !cycle) {
            dfs(graph, *marked.begin(), marked, temp_marked, cycle);
        }

        if(cycle)
            cout << "ORDER VIOLATION" << endl;
        else
            cout << "ORDER EXISTS" << endl;
    }
}
