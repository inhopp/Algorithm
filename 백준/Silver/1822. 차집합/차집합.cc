#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int A[500005];
int B[500005];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++)
        cin >> B[i];

    sort(A, A + N);
    sort(B, B + M);

    vector<int> ans;

    for (int i = 0; i < N; i++) {
        if (binary_search(B,B+M,A[i]))
            continue;

        ans.push_back(A[i]);
    }

    cout << ans.size() << endl;

    if (ans.size() > 0) {
        for (int v : ans)
            cout << v << " ";

        cout << endl;
    }
}