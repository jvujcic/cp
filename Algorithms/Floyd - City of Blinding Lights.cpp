#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> floydWarshall(const vector<vector<int>>& graph) {
  vector<vector<int>> distance;

  distance = graph;

  for (int i = 0; i < graph.size(); i++)
    distance[i][i] = 0;

  for (int k = 0; k < graph.size(); k++)
    for (int i = 0; i < graph.size(); i++)
      for (int j = 0; j < graph.size(); j++)
        if (distance[i][k] >= 0 && distance[k][j] >= 0
            && (distance[i][j] == -1 || distance[i][j] > distance[i][k] + distance[k][j])) {
          distance[i][j] = distance[i][k] + distance[k][j];
        }

  return distance;
}

int main() {
  // freopen("input.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  vector<vector<int>> graph;
  graph.resize(N + 1, vector<int>(N + 1, -1));

  for (int i = 0; i < M; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    graph[x][y] = r;
  }

  vector<vector<int>> solution = floydWarshall(graph);

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    cout << solution[x][y] << endl;
  }

  return 0;
}
