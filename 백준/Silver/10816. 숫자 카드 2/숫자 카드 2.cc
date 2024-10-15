#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int A[500005];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A, A + N);

    cin >> M;

    while(M--) {
        int val;
        cin >> val;

        cout << upper_bound(A, A + N, val) - lower_bound(A, A + N, val) << " ";
    }

    cout << endl;
}