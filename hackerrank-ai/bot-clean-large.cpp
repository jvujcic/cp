#include<iostream>
#include<vector>
#include <string>
#include <limits>
#include <cmath>
#include <random>

using namespace std;

void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> random(0, 1);

    if (board[posr][posc] == 'd') {
        cout << "CLEAN" << endl;
        return;
    }
    int minDist = 9999;
    int minRow = 0;
    int minColumn = 0;

    for (int i = 0; i < dimh; ++i) {
        for (int j = 0; j < dimw; ++j) {
            int tmp = abs(posr - i) + abs(posc - j);
            if (board[i][j] == 'd' && tmp <= minDist) {
                if (tmp == minDist && random(mt) == 1) continue;
                minDist = tmp;
                minRow = i;
                minColumn = j;
            }
        }
    }

    if (minRow == posr) {
        if (minColumn < posc) cout << "LEFT" << endl;
        else cout << "RIGHT" << endl;
        return;
    }
    else {
        if (minRow < posr) cout << "UP" << endl;
        else cout << "DOWN" << endl;
        return;
    }

}
int main(void) {
    int pos[2];
    int dim[2];
    vector <string> board;
    cin >> pos[0] >> pos[1];
    cin >> dim[0] >> dim[1];
    for (int i = 0; i<dim[0]; i++) {
        string s; 
        cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}
