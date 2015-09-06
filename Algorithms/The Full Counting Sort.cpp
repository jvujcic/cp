#include <iostream>
#include <array>
#include <list>
#include <string>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    array<list<string>, 100> myArray;

    for (int i = 0; i < n; ++i) {
        int x; 
        string str;
        cin >> x >> str;
        if (i < n/2) myArray[x].push_back("-");
        else myArray[x].push_back(str);
    }


    for (auto stringList : myArray)
        for (auto str : stringList)
            cout << str << " ";

    cout << endl;
    return 0;
}