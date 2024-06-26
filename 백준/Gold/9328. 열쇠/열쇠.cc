#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define X first
#define Y second

char A[103][103];
int V[103][103];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> Q;
multimap<char, pair<int, int>> R;
set<char> K;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N, M;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;

            for (int j = 0; j < M; j++)
                A[i][j] = s[j];
        }

        cin >> s;
        if (s != "0") {
            for (int i = 0; i < s.length(); i++)
                K.insert(s[i]);
        }

        int cnt = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (i==0 || i==N-1 || j==0 || j==M-1) {
                    if (A[i][j] == '*')
                        continue;

                    else if (A[i][j] == '.') {
                        Q.push({i, j});
                        V[i][j] = 1;
                    }

                    else if ('a'<=A[i][j] && A[i][j]<='z') {
                        Q.push({i, j});
                        V[i][j] = 1;
                        K.insert(A[i][j]);
                    }

                    else if ('A'<=A[i][j] && A[i][j]<='Z')
                        R.insert({A[i][j], {i, j}});
                    
                    else { // '$'
                        Q.push({i, j});
                        V[i][j] = 1;
                        cnt++;
                    }
                }
            }
        Q.push({-2, -2});
        bool flag = true;

        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int x = cur.X + dx[dir];
                int y = cur.Y + dy[dir];

                if (x<0 || x>=N || y<0 || y>=M || A[x][y]=='*' || V[x][y]==1)
                    continue;
                
                if (A[x][y]=='.' && V[x][y]==0) {
                    Q.push({x, y});
                    V[x][y] = 1;
                    continue;
                }

                if (A[x][y]=='$' && V[x][y]==0) {
                    Q.push({x, y});
                    V[x][y] = 1;
                    cnt++;
                    continue;
                }

                if ('a'<=A[x][y] && A[x][y]<='z' && V[x][y]==0) {
                    Q.push({x, y});
                    V[x][y] = 1;
                    K.insert(A[x][y]);
                    flag = true;
                    continue;
                }

                if ('A'<=A[x][y] && A[x][y]<='Z' && V[x][y]==0) {
                    R.insert({A[x][y], {x, y}});
                    flag = true;
                    continue;
                }
            }

            if (!flag)
                continue;

            for (char k : K) {
                k = k - 'a' + 'A';
                auto range = R.equal_range(k);

                for (auto it = range.first; it != range.second; it++) {
                    int x = it->second.X;
                    int y = it->second.Y;

                    Q.push({x, y});
                    V[x][y] = 1;
                }

                R.erase(k);
            }

            flag = false;
        }

        // Initialize
        for (int i = 0; i < N; i++) {
            fill(A[i], A[i] + M, 0);
            fill(V[i], V[i] + M, 0);
        }

        while(!Q.empty()) Q.pop();
        R.clear();
        K.clear();

        cout << cnt << endl;
    }
}