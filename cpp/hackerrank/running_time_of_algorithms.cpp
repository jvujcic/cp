#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &vec) {
    int shift_counter = 0;
    for (int i = 1; i < vec.size(); ++i) {
        int t = vec[i];
        for (int j = i - 1; j >= 0; --j)
            if (vec[j] > t) {
                swap(vec[j + 1], vec[j]);
                ++shift_counter;
            }
            else break;
    }
    cout << shift_counter << endl;

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