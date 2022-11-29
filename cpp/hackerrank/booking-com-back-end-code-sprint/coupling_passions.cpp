#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;
using ll = long long;


const ll EARTH_RADIUS = 6371;
const double PI = 3.14159265359;

double degree_to_radians(double degree) {
    return degree * PI / 180.;
}


struct Point {
    double latitude, longitude;

    double lat_in_rad() {
        return degree_to_radians(latitude);
    }

    double long_in_rad() {
        return degree_to_radians(longitude);
    }
};

double distance_between(Point p1, Point p2) {
    return acos(sin(p1.lat_in_rad()) * sin(p2.lat_in_rad()) +
                cos(p1.lat_in_rad()) * cos(p2.lat_in_rad()) * cos(p2.long_in_rad() - p1.long_in_rad())) * EARTH_RADIUS;
}

struct Destination {
    string name;
    Point coordinates;
    vector<string> passions;
};

struct DestinationPair {
    string name_1, name_2;
    double distance;
    int num_of_passions;

    DestinationPair(const Destination & d1, const Destination & d2, const set<string> & passions) {
        name_1 = d1.name;
        name_2 = d2.name;
        distance = distance_between(d1.coordinates, d2.coordinates);

        vector<string> union_of_passions;
        set_union(d1.passions.begin(), d1.passions.end(), d2.passions.begin(), d2.passions.end(),
                back_inserter(union_of_passions));

        vector<string> intersection_of_passions;
        set_intersection(passions.begin(), passions.end(), union_of_passions.begin(), union_of_passions.end(),
                back_inserter(intersection_of_passions));

        num_of_passions = intersection_of_passions.size();
    }
};

int main() {
    freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;

    vector<vector<string>> persons(n);
    set<string> passions;

    for (ll i = 0; i < n; ++i) {
        ll m;
        cin >> m;

        for (ll j = 0; j < m; ++j) {
            string passion;
            cin >> passion;
            passions.insert(passion);
        }
    }

    ll y;
    cin >> y;
    if (y < 2) return 0;

    vector<Destination> destinations(y);

    for (ll i = 0; i < y; ++i) {
        cin >> destinations[i].name;
        cin >> destinations[i].coordinates.latitude >> destinations[i].coordinates.longitude;

        ll z;
        cin >> z;
        destinations[i].passions.resize(z);

        for (ll j = 0; j < z; ++j) {
            cin >> destinations[i].passions[j];
        }
        sort(destinations[i].passions.begin(), destinations[i].passions.end());
    }

    DestinationPair solution(destinations[0], destinations[1], passions);

    for (ll i = 0; i < y - 1; ++i) {
        for (ll j = i + 1; j < y; ++j) {
            DestinationPair dst_pair(destinations[i], destinations[j], passions);
            if (dst_pair.num_of_passions > solution.num_of_passions ||
                    (dst_pair.num_of_passions == solution.num_of_passions && dst_pair.distance < solution.distance)) {
                solution = dst_pair;
            }
        }
    }

    if (solution.name_1 < solution.name_2) {
        cout << solution.name_1 << " " << solution.name_2 << endl;
    }
    else {
        cout << solution.name_2 << " " << solution.name_1 << endl;
    }

    return 0;
}
