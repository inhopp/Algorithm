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

#define X first
#define Y second

int P[1002];
pair<int, int> Pos[1002];

vector<tuple<double, int, int>> V;

int idx, cnt;
double answer = 0.0;

int find(int x)
{
    while(P[x] > 0)
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

    int N, M;
    cin >> N >> M;

    fill(P + 1, P + N + 1, -1);

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        Pos[i] = {x, y};
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        if (uniFind(x,y))
            cnt++;
    }

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++) {
            double cost = pow(Pos[i].X - Pos[j].X, 2.0) + pow(Pos[i].Y - Pos[j].Y, 2.0);
            cost = sqrt(cost);
            V.push_back({cost, i, j});
        }

    sort(V.begin(), V.end());
    
    while(cnt < N - 1) {
        double cost;
        int x, y;
        tie(cost, x, y) = V[idx++];

        if (!uniFind(x,y))
            continue;

        answer += cost;
        cnt++;
    }

    // 반올림
    cout << fixed;
    cout.precision(2);
    cout << answer << endl;

    return 0;
}