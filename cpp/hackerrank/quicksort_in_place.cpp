#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v) {
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

void quickSort(vector<int> &v, int low, int high) {
    if (low >= high) return;
    int pivot = v[high];
    int freeIndex = low;

    for (int i = low; i < high; ++i)
        if (v[i] < pivot) {
            swap(v[i], v[freeIndex]);
            ++freeIndex;
        }
    swap(v[freeIndex], v[high]);
    printVector(v);
    quickSort(v, low, freeIndex - 1);
    quickSort(v, freeIndex + 1, high);
}

int main() {
    //freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    vector<int> myArray(N);
    for (int i = 0; i < N; ++i)
        cin >> myArray[i];

    quickSort(myArray, 0, N - 1);

    return 0;
}