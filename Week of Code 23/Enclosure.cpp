#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using ui64 = uint64_t;

const double pi = 3.14159265358979323846;
const double e = 0.00001;

double f(const vector<double> & L, double r) {
    double sum = 0;
    for (i64 i = 0; i < L.size(); ++i)
        sum += asin(L[i] / (2*r));
    return sum - pi;
}

double f_der(const vector<double> & L, double r) {
    double sum = 0;
    for (i64 i = 0; i < L.size(); ++i)
        sum += -L[i] / ( 2 * r * r * sqrt((1 - L[i] / (2*r)) * (1 + L[i] / (2*r))));
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    // ios_base::sync_with_stdio(false);
    
    i64 n;
    cin >> n;

    vector<double> L(n);

    for (i64 i = 0; i < n; i++)
        cin >> L[i];

    double r = 0;

    for (i64 i = 0; i < n; i++)
        r += L[i];

    double max_L = *max_element(L.begin(), L.end());

    r = max_L/2 + e;

    for (i64 i = 0; i < 1000; i++) {
        double tmp = r;
        r = r - f(L, r) / f_der(L, r);
        if (abs(tmp - r) < e)
            break;
    }

    double theta = 2 * asin(L[0] / (2*r));
    double a = r * cos(theta / 2);
    double b = r * sin(theta / 2);
    double theta_sum = -pi + theta/2;
    
    cout << 0 << "\n" << 0 << "\n\n";

    for (i64 i = 0; i < L.size() - 1; ++i) {
        double theta_i = 2 * asin(L[i] / (2*r));
        double fi_i = (-theta_i) + theta_sum;
        theta_sum -= theta_i;
        double x_i = a + r * cos(fi_i);
        double y_i = b + r * sin(fi_i);
        cout << fixed << setprecision(12) << x_i << "\n" << y_i << "\n\n";
    }

    return 0;
}

