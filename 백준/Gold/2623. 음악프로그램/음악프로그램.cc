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

int A[1002];
int deg[1002];
vector<int> G[1002];
queue<int> Q;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    while (M--)
    {
        int cnt;
        cin >> cnt;

        for (int i = 0; i < cnt; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < cnt - 1; i++) {
            int u = A[i];
            int v = A[i + 1];

            deg[v]++;
            G[u].push_back(v);
        }

        fill(A, A + cnt, 0);
    }

    for (int i = 1; i <= N; i++)
        if(deg[i] == 0)
            Q.push(i);

    vector<int> answer;

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        answer.push_back(cur);

        for(int nxt : G[cur]) {
            deg[nxt]--;

            if (deg[nxt] == 0)
                Q.push(nxt);
        }
    }

    if (answer.size() == N) 
        for(int a : answer)
            cout << a << "\n";
    
    else
        cout << 0 << endl;
}