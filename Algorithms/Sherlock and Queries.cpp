#include <iostream>
#include <vector>

using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    int N, M;
    const long long MOD = 1000000007;
    cin >> N >> M;
    vector<long long> A(N), B(M), C(M), D(M, 1);

    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < M; ++i)
        cin >> B[i];
    for (int i = 0; i < M; ++i)
        cin >> C[i];


    for (int i = 0; i < M; ++i)
        for (int j = B[i]-1; j < N; j+=B[i])
                A[j] = (A[j] * C[i]) % MOD;

    for(int i = 0; i < N; ++i)
        cout << A[i] << " ";
    return 0;
}
