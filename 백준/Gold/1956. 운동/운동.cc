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

int D[402][402];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        fill(D[i] + 1, D[i] + N + 1, MX);
        D[i][i] = 0;
    }

    while(M--) {
        int x, y, cost;
        cin >> x >> y >> cost;
        D[x][y] = cost;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    int answer = MX;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            answer = min(answer, D[i][j] + D[j][i]);

    if (answer == MX)
        answer = -1;

    cout << answer << endl;

    return 0;
}