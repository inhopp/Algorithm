#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

int A[1003][1003];
int V[12][1003][1003];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<tuple<int, int, int>> Q;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
            A[i][j] = s[j] - '0';
    }

    Q.push({0, 0, 0});
    V[0][0][0] = 1;

    int k, x, y;

    while (!Q.empty()) {
        tie(k, x, y) = Q.front();
        Q.pop();

        if (x==N-1 && y==M-1) {
            cout << V[k][x][y] << endl;
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nk = k + 1;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx<0 || nx>=N || ny<0 || ny>=M)
                continue;
            
            if (A[nx][ny]==0 && V[k][nx][ny]==0) {
                Q.push({k, nx, ny});
                V[k][nx][ny] = V[k][x][y] + 1;
            }

            if (A[nx][ny]==1 && V[nk][nx][ny]==0 && nk<=K) {
                Q.push({nk, nx, ny});
                V[nk][nx][ny] = V[k][x][y] + 1;
            }
        }
    }

    cout << -1 << endl;
}