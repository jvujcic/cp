#include <iostream>
#include <queue>
#include <set>
#include <array>
#include <limits>

using namespace std;

using Matrix = array<array<int, 101>, 101>;

struct square {
    int number;
    int distance;
    square(int n, int d) : number(n), distance(d) {}
    bool operator<(const square &s) const { return (distance < s.distance) ; }
};

void initializeGraph(Matrix &m) {
    for (int i = 0; i < 101; ++i)
        for (int j = 0; j < 101; ++j)
            m[i][j] = -1;
}
void makeGraph(Matrix &m, set<int> &s) {
    for (int i = 1; i < 101; ++i)
        if (s.find(i) == s.end())
            for (int j = i + 1; j < 101 && j <= i + 6; ++j)
                m[i][j] = 1;
    
}

int solve(Matrix &m) {
    multiset<square> q;
    array<int, 101> distance;
    distance.fill(numeric_limits<int>::max());
    distance[1] = 0;
    q.emplace(1, 0);
    while (!q.empty()) {
        int u = q.begin()->number;
        q.erase(q.begin());
        for (int i = 1; i < 101; ++i)
            if (m[u][i] != -1) {
                int alt = distance[u] + m[u][i];
                if (alt < distance[i]) {
                    q.erase(square(i, distance[i]));
                    distance[i] = alt;
                    q.emplace(i, alt);
                }
            }
    }
    return distance[100];
}

int main() {
    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        Matrix graph;
        initializeGraph(graph);
        set<int> S;
        int numberOfSnakes, numberOfLadders, from, to;
        char c;
        cin >> numberOfLadders >> c >> numberOfSnakes;
        for (int j = 0; j < numberOfLadders; ++j) {
            cin >> from >> c >> to;
            graph[from][to] = 0;
            S.insert(from);
        }
        for (int j = 0; j < numberOfSnakes; ++j) {
            cin >> from >> c >> to;
            graph[from][to] = 0;
            S.insert(from);
        }
        makeGraph(graph, S);
        cout << solve(graph) << endl;
    }
    return 0;
}