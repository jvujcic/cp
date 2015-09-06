#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <chrono>
#include <functional>
#include <tuple>
#include <cmath>

using namespace std;

chrono::steady_clock::time_point start;

int currentX, currentY, bestX, bestY, minSquares;

class Grid {
public:
    int x, y, squares = 0, depth = 0;
    double weight = 0;
    vector<string> grid;
    Grid(int x, int y, int depth, vector<string> grid) : x(x), y(y), depth(depth), grid(grid) {
        if (x != -1)
            moveSquares();
        calculateNumberOfSquares();
        calculateComponents();
        calculateWeight();
    }
    bool operator<(const Grid &sq) const {
        return weight > sq.weight;
    }
    void printGrid() {
        cout << "/******************/" << endl;
        for (auto row : grid) {
            cout << row << endl;
        }
        cout << "/******************/" << endl;
    }
    static int removeSquares(int x, int y, vector<string> &grid) {
        char color = grid[x][y];
        queue<pair<int, int>> q;
        q.push(pair<int, int>(x, y));
        grid[x][y] = '-';
        int removed = 0;
        int rows = grid.size();
        int columns = grid[0].size();

        while (!q.empty()) {
            ++removed;
            auto square = q.front();
            q.pop();
            int x = square.first;
            int y = square.second;
            if (x - 1 >= 0 && grid[x - 1][y] == color) {
                q.push(pair<int, int>(x - 1, y));
                grid[x - 1][y] = '-';
            }
            if (y - 1 >= 0 && grid[x][y - 1] == color) {
                q.push(pair<int, int>(x, y - 1));
                grid[x][y - 1] = '-';
            }
            if (x + 1 < rows && grid[x + 1][y] == color) {
                q.push(pair<int, int>(x + 1, y));
                grid[x + 1][y] = '-';
            }
            if (y + 1 < columns && grid[x][y + 1] == color) {
                q.push(pair<int, int>(x, y + 1));
                grid[x][y + 1] = '-';
            }
        }
        return removed;
    }
private:
    map<char, int> numberOfSquares;
    map<char, int> numberOfOneSquares;
    map<char, int> numberOfComponents;

    void calculateNumberOfSquares() {
        for (auto row : grid) {
            for (auto c : row) {
                if (c != '-')
                    squares++;
                    numberOfSquares[c]++;
            }
        }
    }

    void calculateComponents() {
        vector<string> grid = this->grid;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                char color = grid[i][j];
                if (color == '-')
                    continue;
                ++numberOfComponents[color];
                int removed = removeSquares(i, j, grid);
                if (removed == 1) ++numberOfOneSquares[color];
            }
        }
    }

    void calculateWeight() {
        for (auto x : numberOfOneSquares) {
            if (x.second != 0) {
                if (x.second == 1 && numberOfComponents[x.first] == 1) {
                    weight = 1000;
                    return;
                }
                weight += (double(x.second) / numberOfSquares[x.first]);
            }
        }
    }

    void moveVertical(int x, int y) {
        for (int i = x; i > 0; --i)
            grid[i][y] = grid[i - 1][y];

        grid[0][y] = '-';
    }

    void moveHorizontal(int col) {
        for (auto &row : grid) {
            rotate(row.begin() + col, row.begin() + col + 1, row.end());
            row.resize(row.size() - 1);
        }

    }

    void moveSquares() {
        int rows = grid.size();
        int columns = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == '-') moveVertical(i, j);
            }
        }
        for (int j = columns - 2; j >= 0; --j) {
            bool emptyColumn = true;
            for (int i = 0; i < rows; ++i) {
                if (grid[i][j] != '-') {
                    emptyColumn = false;
                    break;
                }
            }
            if (emptyColumn) moveHorizontal(j);
        }

        string emptyRow = string(grid[0].size(), '-');
        int k = 0;
        while (k < grid.size() && grid[k] == emptyRow) { ++k; }
        if (k < grid.size())
            grid = vector<string>(grid.begin() + k, grid.end());
    }
};

void nextMove(int rows, int columns, int color, vector <string> grid) {
    priority_queue<Grid> pq;
    Grid solution(-1, -1, 0, grid);
    pq.push(solution);
    
    while (!pq.empty()) {
        chrono::steady_clock::time_point current;
        current = chrono::steady_clock::now();
        chrono::duration<double> deltaTime = chrono::duration_cast<chrono::duration<double>>(current - start);
        Grid sq = pq.top();
        pq.pop();
        if (solution.x == -1)
            solution = sq;
        if (sq.depth == 5 && (solution < sq || sq.x == 1))
            solution = sq;
        if (deltaTime.count() > 1.7) {
            cout << solution.x << " " << solution.y << endl;
            exit(0);
        }
        if (sq.depth >= 5) continue;
        //sq.printGrid();
        if (sq.x != -1 && sq.squares == 0) {
            cout << sq.x << " " << sq.y << endl;
            exit(0);
        }
        int rows = sq.grid.size();
        int columns = sq.grid[0].size();
        vector<string> tempGrid(sq.grid.begin(), sq.grid.end());

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (tempGrid[i][j] == '-')
                    continue;
                char color = tempGrid[i][j];
                int removedSquares = Grid::removeSquares(i, j, tempGrid);
                if (removedSquares != 1) {
                    vector<string> nextGrid(sq.grid.begin(), sq.grid.end());
                    Grid::removeSquares(i, j, nextGrid);
                    if (sq.x == -1)
                        pq.push(Grid(i, j, sq.depth + 1, nextGrid));
                    else
                        pq.push(Grid(sq.x, sq.y, sq.depth + 1, nextGrid));
                }
            }
        }
    }
    cout << solution.x << " " << solution.y << endl;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    start = chrono::steady_clock::now();
    int x, y, k;
    cin >> x >> y >> k;
    vector <string> grid;

    for (int i = 0; i < x; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    nextMove(x, y, k, grid);
    return 0;
}