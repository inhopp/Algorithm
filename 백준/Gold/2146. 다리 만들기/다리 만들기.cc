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

    int A[101][101];
    int V[2][101][101];

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int, int>> Q;

    int main(void)
    {
        // freopen("input.txt", "r", stdin);

        ios::sync_with_stdio(0);
        cin.tie(0);

        int N;
        cin >> N;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];

        int idx = 1;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (A[i][j] == 0 || V[0][i][j] > 0)
                    continue;

                Q.push({i, j});
                V[0][i][j] = idx;

                while(!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int x = cur.X + dx[dir];
                        int y = cur.Y + dy[dir];

                        if (x<0 || x>=N || y<0 || y>=N)
                            continue;
                        
                        if (A[x][y]==1 && V[0][x][y]==0) {
                            Q.push({x, y});
                            V[0][x][y] = idx;
                        }
                    }
                }

                idx++;
            }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (A[i][j] == 1)
                    Q.push({i, j});

        bool flag = false;
        int res = 1000;

        while (!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int x = cur.X + dx[dir];
                int y = cur.Y + dy[dir];
                
                if (x<0 || x>=N || y<0 || y>= N || A[x][y]==1)
                    continue;
                
                // A[x][y] == 0
                if (V[1][x][y] == 0) {
                    Q.push({x, y});
                    V[1][x][y] = V[1][cur.X][cur.Y] + 1;
                    V[0][x][y] = V[0][cur.X][cur.Y];
                }

                else { // V[1][x][y] > 0
                    if (V[0][cur.X][cur.Y] != V[0][x][y]) {
                        res = min(res, V[1][cur.X][cur.Y] + V[1][x][y]);
                    }
                }
            }
        }

        cout << res << endl;
    }