#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int A[2][100005];
int D[2][100005];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin >> T;

    while(T--) {
        cin >> N;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];

        D[0][0] = A[0][0];
        D[1][0] = A[1][0];
        D[0][1] = A[1][0] + A[0][1];
        D[1][1] = A[0][0] + A[1][1];

        for (int j = 2; j < N; j++) {
            D[0][j] = max(D[1][j - 2], D[1][j - 1]) + A[0][j];
            D[1][j] = max(D[0][j - 2], D[0][j - 1]) + A[1][j];
        }

        cout << max(D[0][N - 1], D[1][N - 1]) << endl;
    }
}