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
#define Z third

int A[105][105][105];
int V[105][105][105];

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

queue<tuple<int, int, int>> Q;
int cnt;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, H;
    cin >> M >> N >> H;

    for (int k = 0; k < H; k++) 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                cin >> A[i][j][k];

                if (A[i][j][k] == 1) {
                    Q.push({i, j, k});
                    V[i][j][k] = 1;
                }
            }

    int cur_x, cur_y, cur_z;

    while (!Q.empty())
    {
        tie(cur_x, cur_y, cur_z) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int x = cur_x + dx[dir];
            int y = cur_y + dy[dir];
            int z = cur_z + dz[dir];

            if (x<0 || x>=N || y<0 || y>=M || z<0 || z>=H)
                continue;
            
            if (A[x][y][z] == 0 && V[x][y][z] == 0) {
                Q.push({x, y, z});
                A[x][y][z] = 1;
                V[x][y][z] = V[cur_x][cur_y][cur_z] + 1;
            }
        }
    }

    int max_cnt = -1;
    for (int k = 0; k < H; k++) 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (A[i][j][k] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
                max_cnt = max(max_cnt, V[i][j][k]);
            }

    cout << max_cnt - 1 << endl;
}