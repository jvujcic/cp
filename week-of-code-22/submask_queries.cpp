#include <iostream>
#include <vector>
#include <bitset>
#include <stack>

using namespace std;

const int SIZE = 100002;

struct Query {
    unsigned long type, x, mask;
    Query(unsigned long type, unsigned long x, unsigned long mask) : type(type), x(x), mask(mask) {}
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<Query> queries;
    queries.reserve(SIZE);
    queries.emplace_back(1, 0, bitset<16>(string(n, '1')).to_ulong());

    vector<Query> backtrace;
    backtrace.reserve(SIZE);

    vector<unsigned long> solutions;
    solutions.reserve(SIZE);

    unsigned int type, x, mask;
    string str_mask;

    for (int i = 0; i < m; ++i) {
        cin >> type;
        if (type == 1 || type == 2) {
            cin >> x >> str_mask;
            mask = bitset<16>(str_mask).to_ulong();
            queries.emplace_back(type, x, mask);

        }
        else {
            cin >> str_mask;
            mask = bitset<16>(str_mask).to_ulong();
            backtrace.clear();
            unsigned long solution;
            for(int j = queries.size() - 1; j >= 0; --j) {
                if ((mask | queries[j].mask) == queries[j].mask) {
                    if (queries[j].type == 1) {
                        solution = queries[j].x;
                        break;
                    }
                    else if (queries[j].type == 2) {
                        backtrace.push_back(queries[j]);
                    }

                }
            }
            for (int j = backtrace.size() - 1; j >= 0; --j) {
                solution ^= backtrace[j].x;
            }

            solutions.push_back(solution);
            //queries.emplace_back(1, solution, mask);
        }
    }

    for (unsigned long x : solutions)
        printf("%lu\n", x);
    return 0;
}
