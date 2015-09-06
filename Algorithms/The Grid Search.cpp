#include <iostream>
#include <vector>
#include <string>

using namespace std;

void findSubGrid(vector<string> &bigGrid, vector<string> &smallGrid) 
{
    for (int i = 0; i < bigGrid.size() - smallGrid.size() + 1; i++) 
    {
        size_t pos = 0;
        size_t found;
        while (pos < bigGrid[i].size()
               && (found = bigGrid[i].find(smallGrid[0], pos)) != string::npos)
        {   
            bool flag = true;
            for (int j = 1; j < smallGrid.size(); j++) 
            {
                if (bigGrid[i+j].substr(found, smallGrid[j].size()) != smallGrid[j]) 
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
                return;
            }

            pos = found + 1;
        }
    }
    cout << "NO" << endl;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int R, C;
        cin >> R >> C;
        vector<string> bigGrid(R);
        for (int j = 0; j < R; j++)
        {
            string row;
            cin >> row;
            bigGrid[j] = row;
        }

        cin >> R >> C;
        vector<string> smallGrid(R);
        for (int j = 0; j < R; j++)
        {
            string row;
            cin >> row;
            smallGrid[j] = row;
        }

        findSubGrid(bigGrid, smallGrid);
    }

    return 0;
}