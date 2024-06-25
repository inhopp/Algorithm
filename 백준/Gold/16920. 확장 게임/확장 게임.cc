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

char A[1003][1003];
int V[1003][1003];
int S[13];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;

int N, M, P;

bool BFS(int p)
{
    bool flag = false;

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (V[cur.X][cur.Y]==S[p]+1) {
            V[cur.X][cur.Y] = 0;
            flag = true;
            continue;
        }

        for (int dir = 0; dir < 4; dir++) {
            int x = cur.X + dx[dir];
            int y = cur.Y + dy[dir];

            if (x<0 || x>=N || y<0 || y>=M)
                continue;
            
            if (A[x][y] == '.') {
                Q.push({x, y});
                A[x][y] = p + '0';
                V[x][y] = V[cur.X][cur.Y] + 1;
            }
        }
    }

    return flag;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> P;

    for (int i = 1; i <= P; i++)
        cin >> S[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    bool flag = true;

    while(flag) {
        flag = false;

        for (int p = 1; p <= P; p++) {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                    if (A[i][j] - '0' == p && V[i][j]==0) {
                        Q.push({i, j});
                        V[i][j] = 1;
                    }
                }
            bool ch = BFS(p);
            flag = flag || ch;
        }
    }

    for (int p = 1; p <= P; p++) {
        int cnt = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (A[i][j]-'0' == p)
                    cnt++;
            }

        cout << cnt << " ";
    }
}