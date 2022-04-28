#include <bits/stdc++.h>

using namespace std;

struct Chess {
    enum class Figure : char {
        NONE = '_', Q = 'Q', N = 'N', B = 'B', R = 'R'
    };

    enum class Color : char {
        NONE = '_', WHITE = 'W', BLACK = 'B'
    };

    Chess() {}
    Chess(vector<vector<pair<Color, Figure>>> b) : board(b) {}

    vector<vector<pair<Color, Figure>>> board{4, vector<pair<Color, Figure>>{4, {Color::NONE, Figure::NONE}}};

    void set(int x, int y, char figure, char color) {
        board[x][y] = {(Color)color, (Figure)figure};
    }

    void set(int x, int y, Color color, Figure figure) {
        board[x][y] = {color, figure};
    }

    pair<bool, Chess> move_straight(int x, int y, int d_h, int d_v) {
        bool flag;
        Chess chess;
        if ((d_h != 0 && d_v != 0 && abs(d_h) != abs(d_v)) || (d_h == 0 && d_v == 0))
            return {false, chess};
        if (x + d_h < 0 || x + d_h > 3 || y + d_v < 0 || y + d_v > 3)
            return {false, chess};
        if (board[x+d_h][y+d_v].first == board[x][y].first)
            return {false, chess};

        int step_h = d_h != 0 ? d_h / abs(d_h) : 0;
        int step_v = d_v != 0 ? d_v / abs(d_v) : 0;
        int sum_step = d_h != 0 ? abs(d_h) - 1 : abs(d_v) - 1;
        for (int i = x + step_h, j = y + step_v; sum_step > 0; i += step_h, j += step_v, sum_step--) {
            if (board[i][j].first != Color::NONE)
                return {false, chess};
        }

        chess.board = board;
        chess.board[x+d_h][y+d_v] = board[x][y];
        chess.set(x, y, Color::NONE, Figure::NONE);
        return {true, chess};
    }

    pair<bool, Chess> move_L(int x, int y, int d_h, int d_v) {
        bool flag;
        Chess chess;
        if (!((abs(d_h) == 1 && abs(d_v) == 2) || (abs(d_h) == 2 && abs(d_v) == 1)))
            return {false, chess};
        if (x + d_h < 0 || x + d_h > 3 || y + d_v < 0 || y + d_v > 3)
            return {false, chess};
        if (board[x+d_h][y+d_v].first == board[x][y].first)
            return {false, chess};

        chess.board = board;
        chess.board[x+d_h][y+d_v] = board[x][y];
        chess.set(x, y, Color::NONE, Figure::NONE);
        return {true, chess};
    }

    void print() {
        for (int j = 3; j >= 0 ; --j) {
            for (int i = 0; i < 4; ++i)
                cout << (char)board[i][j].first << (char)board[i][j].second << " ";
            cout << endl;
        }
    }
};

int dfs_minimax(Chess chess, int depth, bool is_white) {
    pair<Chess::Color, Chess::Figure> bq{Chess::Color::BLACK, Chess::Figure::Q};
    pair<Chess::Color, Chess::Figure> wq{Chess::Color::WHITE, Chess::Figure::Q};
    bool white_queen = false;
    bool black_queen = false;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (chess.board[i][j] == bq)
                black_queen = true;
            else if (chess.board[i][j] == wq)
                white_queen = true;

    if (white_queen && !black_queen) return 1;
    if (!white_queen && black_queen) return -1;
    if (depth == 0) return -1;

    Chess::Color c = is_white ? Chess::Color::WHITE : Chess::Color::BLACK;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            Chess::Color color = chess.board[i][j].first;
            Chess::Figure figure = chess.board[i][j].second;
            if (color == c) {
                if (figure == Chess::Figure::Q || figure == Chess::Figure::R) {
                    vector<pair<int, int>> comb = {
                        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
                        {2, 0}, {-2, 0}, {0, 2}, {0, -2},
                        {3, 0}, {-3, 0}, {0, 3}, {0, -3},
                    };
                    for (auto p : comb) {
                        auto result = chess.move_straight(i, j, p.first, p.second);
                        if (result.first) {
                            int v = dfs_minimax(result.second, depth - 1, !is_white);
                            if (is_white && v == 1) return 1;
                            if (!is_white && v == -1) return -1;
                        }
                    }
                }
                if (figure == Chess::Figure::Q || figure == Chess::Figure::B) {
                    vector<pair<int, int>> comb = {
                        {1, 1}, {-1, 1}, {1, -1}, {-1, -1},
                        {2, 2}, {-2, 2}, {2, -2}, {-2, -2},
                        {3, 3}, {-3, 3}, {3, -3}, {-3, -3},
                    };
                    for (auto p : comb) {
                        auto result = chess.move_straight(i, j, p.first, p.second);
                        if (result.first) {
                            int v = dfs_minimax(result.second, depth - 1, !is_white);
                            if (is_white && v == 1) return 1;
                            if (!is_white && v == -1) return -1;
                        }
                    }
                }
                if (figure == Chess::Figure::N) {
                    vector<pair<int, int>> comb = {
                        {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
                    };
                    for (auto p : comb) {
                        auto result = chess.move_L(i, j, p.first, p.second);
                        if (result.first) {
                            int v = dfs_minimax(result.second, depth - 1, !is_white);
                            if (is_white && v == 1) return 1;
                            if (!is_white && v == -1) return -1;
                        }
                    }
                }
            }
        }
    }

    if(is_white) return -1;
    else return 1;
}

bool is_white_winner(const Chess & chess, int moves) {
    if (moves % 2 == 0) moves--;
    if (dfs_minimax(chess, moves, true) == 1) return true;
    else return false;
}


void solve() {
    int w, b, m;
    cin >> w >> b >> m;
    Chess chess;

    for (int i = 0; i < w; ++i) {
        char figure, x;
        int y;
        cin >> figure >> x >> y;
        chess.set(x - 'A', y - 1, figure, 'W');

    }
    for (int i = 0; i < b; ++i) {
        char figure, x;
        int y;
        cin >> figure >> x >> y;
        chess.set(x - 'A', y - 1, figure, 'B');
    }
    if (is_white_winner(chess, m))  cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);

    int g;
    cin >> g;

    for (int i = 0; i < g; ++i)
        solve();
}