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

int V[505];
vector<int> G[505];
bool isTree;

void DFS(int cur, int prev)
{
    V[cur] = 1;
    for(int nxt : G[cur]) {
        if (nxt == prev)
            continue;

        if (V[nxt] == 1) {
            isTree = false;
            continue;
        }

        DFS(nxt, cur);
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int caseNumber = 1;

    while(true) {
        cin >> N >> M;

        if (N==0 && M==0)
            break;

        fill(V, V + N + 1, 0);
        for (int i = 1; i <= N; i++)
            G[i].clear();

        while(M--) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int numTrees = 0;
        for (int i = 1; i <= N; i++) {
            if (V[i] == 1)
                continue;

            isTree = true;
            DFS(i, -1);
            numTrees += isTree;
        }

        cout << "Case " << caseNumber << ": ";
        
        if (numTrees == 0) {
            cout << "No trees.\n";
        }

        else if (numTrees == 1) {
            cout << "There is one tree.\n";
        }

        else {
            cout << "A forest of " << numTrees << " trees.\n";
        }

        caseNumber++;
    }

    return 0;
}