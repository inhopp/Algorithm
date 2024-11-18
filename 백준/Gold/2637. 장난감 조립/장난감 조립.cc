#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int Table[102][102];
int indeg[102];
vector<int> Graph[102];
queue<int> Q;

int N, M, X, Y, K;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> X >> Y >> K;

        indeg[X]++;
        Table[X][Y] += K;
        Graph[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++)
        if (indeg[i] == 0) {
            Q.push(i);
            Table[i][i] = 1;
        }

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        for(int nxt : Graph[cur]) {
            int mult = Table[nxt][cur];
            Table[nxt][cur] = 0;

            for (int i = 1; i <= N; i++) {
                Table[nxt][i] += mult * Table[cur][i];
            }

            indeg[nxt]--;
            if (indeg[nxt] == 0)
                Q.push(nxt);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (Table[N][i] == 0)
            continue;

        cout << i << " " << Table[N][i] << "\n";
    }

    return 0;
}