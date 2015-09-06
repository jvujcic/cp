#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int> &v) {
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

void insertionSort(vector<int> &ar) {
    int v = ar.back();
    for (int i = ar.size() - 2; i >= 0; --i)
        if (ar[i] > v) {
            ar[i + 1] = ar[i];
            print_vector(ar);
        }
        else {
            ar[i + 1] = v;
            print_vector(ar);
            return;
        }
        ar[0] = v;
        print_vector(ar);
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