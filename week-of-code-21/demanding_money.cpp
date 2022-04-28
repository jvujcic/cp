#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long possible_solutions[3401];
int graph[34][34];
int C[34];
int current_max = 0;

void rec(set<int> still_free, int stolen) {
    for(auto it = still_free.begin(); it != still_free.end();) {
        int v = *it;
        it = still_free.erase(it);
        set<int> new_still_free(still_free);
        int new_stolen = stolen + C[v];
        possible_solutions[new_stolen]++;
        if (current_max < new_stolen) current_max = new_stolen;
        for(int i = 0; i < 34; i++)
            if(graph[v][i] == 1) new_still_free.erase(i);

        int left_over_money = 0;
        for(auto it = new_still_free.begin(); it != new_still_free.end(); ++it)
            left_over_money += C[*it];

        if (new_stolen + left_over_money >= current_max) rec(new_still_free, new_stolen);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    set<int> still_free;

    for (int i = 0; i < N; i++) {
        cin >> C[i];
        still_free.insert(i);
    }

    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        graph[v-1][w-1] = 1;
        graph[w-1][v-1] = 1;
    }

    rec(still_free, 0);

    cout << current_max << " " << possible_solutions[current_max] << endl;

    return 0;
}