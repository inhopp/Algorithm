#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <math.h>
#include <tuple>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int W[302];
int A[302][302];
int P[302];

int find(int x)
{
    while (P[x] > 0)
        x = P[x];

    return x;
}

bool uniFind(int u, int v)
{
    int r1 = find(u);
    int r2 = find(v);

    if (r1 == r2)
        return false;

    if (P[r1] == P[r2]) {
        P[r1]--;
        P[r2] = r1;
    }

    else {
        if (P[r1] < P[r2])
            P[r2] = r1;

        else
            P[r1] = r2;
    }

    return true;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> W[i];

    fill(P + 1, P + N + 2, -1);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    int cnt = 0;
    int answer = 0;

    vector<tuple<int, int, int>> V;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            V.push_back({ A[i][j], i, j });

    for (int i = 1; i <= N; i++) 
        V.push_back({ W[i], i, N + 1});

    sort(V.begin(), V.end());
    int idx = 0;

    while (cnt < N) {
        int cost, u, v;
        tie(cost, u, v) = V[idx++];

        if (!uniFind(u, v))
            continue;

        answer += cost;
        cnt++;
    }

    cout << answer << endl;

    return 0;
}