#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

void move_crates(vector<deque<char>>& stacks, ll n, ll from, ll to) {
    deque<char> temp;

    copy(stacks[from].rbegin(), stacks[from].rbegin() + n, front_inserter(temp));

    stacks[from].erase(stacks[from].end() - n, stacks[from].end());

    copy(temp.begin(), temp.end(), back_inserter(stacks[to]));
}

int main() {
    stringstream ss;
    ss << cin.rdbuf();

    string input = ss.str();
    auto empty_line_index = input.find("\n\n");
    auto end_of_stacks_index = input.substr(0, empty_line_index).find_last_of('\n');
    ll num_of_stacks = stoll(input.substr(empty_line_index - 2, 1));

    auto stacks = vector<deque<char>>(num_of_stacks);
    string line;
    ss = stringstream(input.substr(0, end_of_stacks_index));

    while (getline(ss, line)) {
        ll column = 0;
        for (ull k = 1; k < line.length(); k += 4) {
            if (line[k] != ' ')
                stacks[column].push_front(line[k]);
            column++;
        }
    }

    ss = stringstream(input.substr(empty_line_index + 2, input.length()));
    while (getline(ss, line)) {
        ll n, from, to;
        sscanf(line.c_str(), "move %lld from %lld to %lld", &n, &from, &to);
        move_crates(stacks, n, from - 1, to - 1);  // -1 because we index from 0
    }

    for (int i = 0; i < num_of_stacks; i++)
        cout << stacks[i].back();
    return 0;
}