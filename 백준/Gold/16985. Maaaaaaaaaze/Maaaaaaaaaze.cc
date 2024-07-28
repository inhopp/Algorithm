#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int A[5][5][5];
int B[5][5][5];
int V[5][5][5];
int dx[6] = {0, 1, 0, 0, -1, 0};
int dy[6] = {0, 0, 1, 0, 0, -1};
int dz[6] = {1, 0, 0, -1, 0, 0};
queue<tuple<int, int, int>> Q;

int P[5] = {0, 1, 2, 3, 4};
int mn = 10000;
bool flag = false;

void copyInitialize()
{
    for (int k = 0; k < 5; k++)
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                B[P[k]][i][j] = A[k][i][j];
}

void rotate(int layer, int dir)
{
    for (int k = 0; k < dir; k++) {
        int temp[5][5];
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                temp[i][j] = B[layer][i][j];

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                B[layer][i][j] = temp[4 - j][i];
    }
}

bool BFS()
{
    Q.push({0, 0, 0});
    V[0][0][0] = 1;

    int x, y, z;
    while (!Q.empty()) {
        tie(z, x, y) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nz = z + dz[dir];
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nz<0 || nz>=5 || nx<0 || nx>=5 || ny<0 || ny>=5)
                continue;

            if (B[nz][nx][ny]==1 && V[nz][nx][ny]==0) {
                Q.push({nz, nx, ny});
                V[nz][nx][ny] = V[z][x][y] + 1;

                if (nz==4 && nx==4 && ny==4) {
                    while(!Q.empty())
                        Q.pop();

                    mn = min(mn, V[nz][nx][ny] - 1);
                    return true;
                }
            }
        }
    }

    return false;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int k = 0; k < 5; k++) 
        for (int i = 0; i < 5; i++) 
            for (int j = 0; j < 5; j++) 
                cin >> A[k][i][j];

    do {
        for (int tmp = 0; tmp < 1024; tmp++) {
            copyInitialize();
            int brute = tmp;

            for (int layer = 0; layer < 5; layer++) {
                int dir = brute % 4;
                brute /= 4;

                rotate(layer, dir);
            }

            if (B[0][0][0] == 0)
                continue;

            flag |= BFS();

            for (int k = 0; k < 5; k++)
                for (int i = 0; i < 5; i++)
                    fill(V[k][i], V[k][i] + 5, 0);
        }

    } while (next_permutation(P, P + 5));

    if (flag)
        cout << mn << endl;
    else
        cout << -1 << endl;
}