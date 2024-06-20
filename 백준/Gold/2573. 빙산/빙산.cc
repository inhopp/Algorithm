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

int A[305][305];
int B[305][305];
int V[305][305];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;

int N, M;
int cnt = 1;
int res;

void Melting()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] > 0) {
                int sub = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int x = i + dx[dir];
                    int y = j + dy[dir];

                    if (A[x][y] == 0)
                        sub++;
                }

                B[i][j] = max(A[i][j] - sub, 0);
            }

            else
                B[i][j] = 0;
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            A[i][j] = B[i][j];
}

int Counting()
{
    cnt = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (A[i][j] > 0 && V[i][j] == 0) {
                Q.push({i, j});
                V[i][j] = 1;
                cnt++;

                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int x = cur.X + dx[dir];
                        int y = cur.Y + dy[dir];

                        if (x<0 || x>=N || y<0 || y>=M)
                            continue;
                        
                        if (A[x][y] > 0 && V[x][y] == 0) {
                            Q.push({x, y});
                            V[x][y] = 1;
                        }
                    }
                }
            }
        }

    for (int i = 0; i < N; i++)
        fill(V[i], V[i] + M, 0);

    return cnt;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    
    while(cnt == 1) {
        Melting();
        cnt = Counting();
        res++;
    }

    if (cnt == 0)
        cout << 0 << endl;
    else
        cout << res << endl;
}