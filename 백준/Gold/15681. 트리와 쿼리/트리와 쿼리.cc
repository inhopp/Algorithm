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

// 100005
int P[100005];
vector<int> T[100005];
int Count[100005];
int N, R, Q;

int BFS(int cur)
{
    P[cur] = 1;
    for(int nxt : T[cur]) {
        if (P[nxt] == 1)
            continue;

        Count[cur] += BFS(nxt);
    }
    Count[cur]++;

    return Count[cur];
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    BFS(R);

    while (Q--) {
        int root;
        cin >> root;

        cout << Count[root] << "\n";
    }

    return 0;
}