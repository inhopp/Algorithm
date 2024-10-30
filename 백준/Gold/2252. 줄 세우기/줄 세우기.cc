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

int deg[32005];
vector<int> G[32005];
queue<int> Q;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    while(M--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        deg[v]++;
    }

    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0)
            Q.push(i);
    }

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        cout << cur << " ";

        for(int nxt : G[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0)
                Q.push(nxt);
        }
    }

    cout << endl;

    return 0;
}