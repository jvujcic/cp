#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

struct vec {
    double x, y;

    vec(double x = 0, double y = 0) : x(x), y(y) {}
    
    vec operator+(const vec & v) const {
        return vec(x + v.x, y + v.y);
    }

    vec operator-() const {
        return vec(-x, -y);
    }

    vec operator-(const vec & v) const {
        return *this + (-v);
    }

    double operator*(const vec & v) const {
        return x*v.x + y*v.y;
    }

    double sq_norm() const {
        return (*this) * (*this);
    }

    double norm() const {
        return sqrt(sq_norm());
    }

    vec operator*(double f) const {
        return vec(x*f, y*f);
    }
};

bool counterlockwise(const vec & v, const vec & w) {
    return v.x * w.y - v.y*w.x < 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);

    vec point, v;

    cin >> point.x >> point.y >> v.x >> v.y;

    vec proj = v*(point*v)*(1/v.sq_norm());
    double k = sqrt(proj.sq_norm() / v.sq_norm());

    cout << k << endl;

    vec ort = proj  - point;

    double n = sqrt(ort.sq_norm() / v.sq_norm());

    if (counterlockwise(proj, ort))
        cout << fixed << setprecision(12) << n << endl;
    else
        cout << fixed << setprecision(12) << -n << endl;

    return 0;
}