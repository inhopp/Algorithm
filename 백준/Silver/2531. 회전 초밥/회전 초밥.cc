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

int A[33005];
unordered_map<int, int> UM;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, D, K, C;
    cin >> N >> D >> K >> C;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < K; i++) {
        A[i + N] = A[i];
        UM[A[i]] += 1;
    }

    int idx = K;
    int mx = 0, size = 0;

    while (idx < N + K) {
        if (UM.find(C) == UM.end())
            size = int(UM.size());
        else
            size = int(UM.size()) - 1;

        mx = max(mx, size);

        if (UM[A[idx-K]] == 1)
            UM.erase(A[idx - K]);
        else
            UM[A[idx - K]] -= 1;

        UM[A[idx]] += 1;

        idx++;
    }

    cout << mx + 1 << endl;
}