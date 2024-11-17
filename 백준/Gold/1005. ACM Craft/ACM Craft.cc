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

int Time[1005];
int indeg[1005];
int D[1005];
vector<int> Graph[1005];
queue<int> Q;

int T, N, K, X, Y, W;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N >> K;

        for (int i = 1; i <= N; i++)
            cin >> Time[i];

        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            Graph[X].push_back(Y);
            indeg[Y]++;
        }

        cin >> W;

        for (int i = 1; i <= N; i++)
            if (indeg[i] == 0) {
                Q.push(i);
            }

        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            for(int nxt : Graph[cur]) {
                D[nxt] = max(D[nxt], D[cur] + Time[cur]);
                indeg[nxt]--;
                if (indeg[nxt] == 0)
                    Q.push(nxt);
            }
        }

        cout << D[W] + Time[W] << "\n";

        // Initialize
        fill(Time, Time + N + 1, 0);
        fill(indeg, indeg + N + 1, 0);
        fill(D, D + N + 1, 0);
        for (int i = 1; i <= N; i++)
            Graph[i].clear();
    }
}