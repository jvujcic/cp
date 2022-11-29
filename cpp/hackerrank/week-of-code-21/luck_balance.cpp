#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int N, K;
    cin >> N >> K;

    int L, T;
    int solution = 0;
    vector<int> luck;

    for (int i = 0; i < N; ++i) {
        cin >> L >> T;
        if (T == 0) {
            solution += L;
            continue;
        }
        luck.push_back(L);
    }

    sort(luck.begin(), luck.end());
    
    if (K > luck.size()) K = luck.size();

    for (int i = 0; i < luck.size() - K; ++i)
        solution -= luck[i];
    for (int i = luck.size() - K; i < luck.size(); ++i)
        solution += luck[i];

    cout << solution << endl;

    return 0;
}