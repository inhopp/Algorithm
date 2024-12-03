#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define MX 0x3f3f3f3f

int D[102][102];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (i==j)
                D[i][j] = 0;
            
            else
                D[i][j] = MX;
    }

    for (int i = 1; i <= M; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;

        D[x][y] = min(D[x][y], cost);
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (D[i][j] == MX)
                D[i][j] = 0;
            cout << D[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}