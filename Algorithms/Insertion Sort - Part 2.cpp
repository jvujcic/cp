#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int> &v) {
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

void insertionSort(vector<int> &vec) {
    for (int i = 1; i < vec.size(); ++i) {
        int t = vec[i];
        for (int j = i - 1; j >= 0; --j)
            if (vec[j] > t) swap(vec[j + 1], vec[j]);
            else break;
            print_vector(vec);
    }

}

int main() {
    //freopen("input.txt", "r", stdin);

    int s;
    cin >> s;

    vector<int> ar(s);
    for (int i = 0; i < s; i++)
        cin >> ar[i];

    insertionSort(ar);
    return 0;
}