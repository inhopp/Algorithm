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

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, u, v;
    cin >> N >> M;

    vector<int> G[102];

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    queue<int> Q;
    int Vis[102];
    fill(Vis, Vis + N, 0);

    Q.push(1);
    Vis[1] = 1;

    int answer = 0;

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        answer++;

        for(int i : G[cur]) {
            if (Vis[i] == 1)
                continue;

            Q.push(i);
            Vis[i] = 1;
        }
    }

    cout << answer - 1 << endl;
}