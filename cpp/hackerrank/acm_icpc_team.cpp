#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numberOfTopics(string str1, string str2) {
    int count = 0;
    for (int i = 0; i < str1.size(); ++i)
        if (str1[i] == '1' || str2[i] == '1') ++count;
    return count;
}

void solve(vector<string> &binary) {
    int maxTopics = 0;
    int maxPairs = 0;
    for (int i = 0; i < binary.size() - 1; ++i)
        for (int j = i + 1; j < binary.size(); ++j) {
            int nTopics = numberOfTopics(binary[i], binary[j]);
            if (nTopics > maxTopics) {
                maxTopics = nTopics;
                maxPairs = 1;
            }
            else if (nTopics == maxTopics)
                ++maxPairs;
        }
    cout << maxTopics << endl;
    cout << maxPairs << endl;
}

int main() {
    //freopen("input.txt","r",stdin);

    int numberOfPeople = 0;
    cin >> numberOfPeople;
    
    int numberOFTopics = 0;
    cin >> numberOFTopics;

    vector<string> binary(numberOfPeople);

    for (int i = 0; i < numberOfPeople; ++i)
        cin >> binary[i];

    solve(binary);
}