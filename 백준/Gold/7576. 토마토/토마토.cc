#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

#define X first
#define Y second

int A[1005][1005];
int V[1005][1005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int total_size;
int cur_size;
int max_cnt;

queue<pair<int, int>> Q;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> M >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];

            if (A[i][j] == -1)
                continue;

            if (A[i][j] == 1) {
                Q.push({i, j});
                cur_size++;
            }

            total_size++;
        }

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int x = cur.X + dx[dir];
            int y = cur.Y + dy[dir];

            if (x<0 || x>=N || y<0 || y>=M)
                continue;
            
            if (A[x][y] == 0) {
                Q.push({x, y});
                A[x][y] = 1;
                V[x][y] = V[cur.X][cur.Y] + 1;
                cur_size++;
                max_cnt = max(max_cnt, V[x][y]);
            }
        }
    }
    
    if (cur_size == total_size)
        cout << max_cnt << endl;
    
    else
        cout << -1 << endl;
}
