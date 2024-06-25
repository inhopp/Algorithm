#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define X first
#define Y second

int A[1003][1003];
int V[1003][1003];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;
multimap<pair<int, int>, pair<int, int>> L;

int cnt;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int x1, y1, x2, y2;

    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        L.insert({{x1 - 1, y1 - 1}, {x2 - 1, y2 - 1}});
    }

    Q.push({0, 0});
    A[0][0] = 1;
    V[0][0] = 1;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        auto range = L.equal_range({cur.X, cur.Y});
        for (auto it = range.first; it != range.second; it++) {
            int x = (it->second).X;
            int y = (it->second).Y;

            if (V[x][y]==1)
                continue;

            A[x][y] = 1;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx<0 || nx>=N || ny<0 || ny>=N)
                    continue;
                
                if (V[nx][ny]==1) {
                    Q.push({x, y});
                    V[x][y] = 1;
                    break;
                }
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx<0 || nx>=N || ny<0 || ny>=N || A[nx][ny]==0)
                continue;
            
            if (V[nx][ny]==0) {
                Q.push({nx, ny});
                V[nx][ny] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (A[i][j]==1)
                cnt++;

    cout << cnt << endl;
}