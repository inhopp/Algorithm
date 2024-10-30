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

int P[100005];
vector<int> T[100005];

void BFS(int root) {
    queue<int> Q;
    Q.push(root);

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        for (int nxt : T[cur]) {
            if (nxt == P[cur])
                continue;

            Q.push(nxt);
            P[nxt] = cur;
        }
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    BFS(1);

    for (int i = 2; i <= N; i++) {
        cout << P[i] << "\n";
    }

    return 0;
}