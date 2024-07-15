#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <set>

using namespace std;

#define X first
#define Y second

int A[5][5];
int V[5][5];
int VV[5][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

int P[25];
int res;

bool connected()
{
    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (V[i][j] == 0 || VV[i][j] == 1)
                continue;

            Q.push({i, j});
            VV[i][j] = 1;
            cnt++;

            while(!Q.empty()) {
                auto cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx<0 || nx>=5 || ny<0 || ny>=5)
                        continue;
                    
                    if (V[nx][ny]==1 && VV[nx][ny]==0) {
                        Q.push({nx, ny});
                        VV[nx][ny] = 1;
                    }
                }
            }
        }
    }

    if (cnt==1)
        return true;

    return false;
}

void initialize()
{
    for (int i = 0; i < 5; i++) {
        fill(V[i], V[i] + 5, 0);
        fill(VV[i], VV[i] + 5, 0);
    }
}

int counting()
{
    int cnt = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            if (A[i][j]==1 && V[i][j]==1)
                cnt++;
        }
    
    return cnt;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 5; j++) {
            if (s[j] == 'Y')
                A[i][j] = 0;
            else
                A[i][j] = 1;
        }
    }

    for (int i = 18; i < 25; i++)
        P[i] = 1;

    do {
        for (int i = 0; i < 25; i++) {
            int r = i / 5;
            int c = i % 5;

            V[r][c] = P[i];
        }

        if (!connected()) {
            initialize();
            continue;
        }

        int cnt = counting();

        if (cnt >=4)
            res++;

        initialize();
    } while (next_permutation(P, P + 25));

    cout << res << endl;
}