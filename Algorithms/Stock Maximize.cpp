#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long maximumProfit(vector<int> &stock) {
    auto begin = stock.begin();
    auto maxIterator = max_element(stock.begin(), stock.end());
    long solution = 0;
    long numberOfStocks = 0;
    while (begin != stock.end()) {
        for (auto it = begin; it != maxIterator; ++it) {
            solution -= *it;
            ++numberOfStocks;
        }
        solution += numberOfStocks * (*maxIterator);
        numberOfStocks = 0;       
        begin = maxIterator + 1;
        maxIterator = max_element(begin, stock.end());
    }
    return solution;
}

int main() {
    //freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        vector<int> stock(N);
        for (int j = 0; j < N; ++j)
            cin >> stock[j];
        cout << maximumProfit(stock) << endl;
    }

    return 0;
}