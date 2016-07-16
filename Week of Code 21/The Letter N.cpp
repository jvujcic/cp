#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;


vector<vector<double>> angles;
vector<vector<double>> sorted_angles;

struct Point {
    int x, y;
};

LL number_of_sides(int i, int j) {
    double deg = angles[i][j];
        LL sides;
        if (deg >= 90) {
            double l = deg - 90;
            sides = upper_bound(sorted_angles[i].begin(), sorted_angles[i].end(), deg) -
                     lower_bound(sorted_angles[i].begin(), sorted_angles[i].end(), l);

        }
        else {
            sides = upper_bound(sorted_angles[i].begin(), sorted_angles[i].end(), deg) -
                     lower_bound(sorted_angles[i].begin(), sorted_angles[i].end(), 0);
            sides += upper_bound(sorted_angles[i].begin(), sorted_angles[i].end(), 360) -
                      lower_bound(sorted_angles[i].begin(), sorted_angles[i].end(), deg + 270);
        }
        return --sides;
}

int main() {
    freopen("input.txt", "r", stdin);
    
    int N;
    cin >> N;

    vector<Point> points(N);

    for (int i = 0; i < N; ++i) {
        cin >> points[i].x;
        cin >> points[i].y;    
    }

    angles = vector<vector<double>>(N, vector<double>(N));
    sorted_angles = vector<vector<double>>(N, vector<double>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double deg = atan2(points[j].y - points[i].y, points[j].x - points[i].x) * 180.0 / M_PI;
            if ( deg < 0) deg += 360;
            angles[i][j] = deg;
        }
        angles[i][i] = -1;
        sorted_angles[i] = angles[i];
        sort(sorted_angles[i].begin(), sorted_angles[i].end());

    }

    LL solution = 0;

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            LL side_1 = number_of_sides(i, j);
            LL side_2 = number_of_sides(j, i);
            solution += side_1 * side_2;
        }
    }

    cout << solution << endl;
    return 0;
}

