#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool dfs(vector<vector<bool>> & graph, int u, vector<bool> & seen, vector<int> & match)
{
    for (unsigned int v = 0; v < graph.size(); v++)
    {
        if (graph[u][v] && !seen[v])
        {
            seen[v] = true;

            if (match[v] < 0 || dfs(graph, match[v], seen, match))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int max_matching(vector<vector<bool>> graph)
{
    vector<int> match(graph.size(), -1);

    int result = 0;
    for (unsigned int u = 0; u < graph.size(); u++)
    {
        vector<bool> seen(graph.size(), false);
 
        if (dfs(graph, u, seen, match))
            result++;
    }
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<set<string>> passions(n);
    vector<vector<bool>> graph(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        int c, p;
        cin >> c >> p;
        for (int j = 0; j < p; j++) {
            string passion;
            cin >> passion;
            passions[i].insert(passion);
        }
    }

    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        for (int j = 0; j < e; j++) {
            string passion;
            cin >> passion;
            for (int k = 0; k < n; k++)
                if (passions[k].count(passion) > 0)
                    graph[k][i] = true;
        }
    }

    cout << max_matching(graph) << endl;
    return 0;
}
