#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

vector<pair<int, int>> V;
priority_queue<int, vector<int>, std::greater<int>> Q;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, s, e;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        V.push_back({s, e});
    }

    sort(V.begin(), V.end());

    Q.push({V[0].second});

    for (int i = 1; i < V.size(); i++) {
        s = V[i].first;
        e = V[i].second;

        if (s >= Q.top())
            Q.pop();

        Q.push(e);
    }

    cout << Q.size() << endl;
}