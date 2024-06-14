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

char A[1005][1005];
int V1[1005][1005];
int V2[1005][1005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N, M;
    cin >> T;

    while(T--) {
        cin >> M >> N;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];

                if (A[i][j] == '@') {
                    Q1.push({i, j});
                    V1[i][j] = 1;
                    A[i][j] = '.';
                }

                if (A[i][j] == '*') {
                    Q2.push({i, j});
                    V2[i][j] = 1;
                }
            }
        
        // Fire 
        while(!Q2.empty()) {
            auto cur = Q2.front();
            Q2.pop();

            for (int dir = 0; dir < 4; dir++) {
                int x = cur.X + dx[dir];
                int y = cur.Y + dy[dir];

                if (x<0 || x>=N || y<0 || y>=M) 
                    continue;
                
                if (A[x][y] == '.' && V2[x][y] == 0) {
                    Q2.push({x, y});
                    V2[x][y] = V2[cur.X][cur.Y] + 1;
                }
            }
        }

        // Person
        bool flag = false;
        while (!Q1.empty()) {
            auto cur = Q1.front();
            Q1.pop();

            if (cur.X==0 || cur.X==N-1 || cur.Y==0 || cur.Y==M-1) {
                cout << V1[cur.X][cur.Y] << endl;
                flag = true;
                break;
            }

            for (int dir = 0; dir < 4; dir++) {
                int x = cur.X + dx[dir];
                int y = cur.Y + dy[dir];

                if (x<0 || x>=N || y<0 || y>=M)
                    continue;
                
                if (A[x][y] == '.' && V1[x][y]==0)
                    if (V2[x][y]==0 || V1[cur.X][cur.Y]+1 < V2[x][y]) {
                        Q1.push({x, y});
                        V1[x][y] = V1[cur.X][cur.Y] + 1;
                }
            }
        }

        if (!flag)
            cout << "IMPOSSIBLE" << endl;

        while(!Q1.empty())
            Q1.pop();
        
        while(!Q2.empty())
            Q2.pop();

        for (int i = 0; i < 1005; i++) {
            fill(V1[i], V1[i] + 1005, 0);
            fill(V2[i], V2[i] + 1005, 0);
        }
    }
}