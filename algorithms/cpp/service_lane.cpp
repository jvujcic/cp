#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> laneWidth;
    laneWidth.reserve(N);

    while(N--)
    {
        int width;
        cin >> width;
        laneWidth.push_back(width);
    }

    while(T--) {
        int entry, end;
        cin >> entry >> end;
        int min = 4;
        for(int i = entry; i <= end; i++)
            if(laneWidth[i] < min)
                min = laneWidth[i];
        cout << min << endl;
    }

    return 0;
}