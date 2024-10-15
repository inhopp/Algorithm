#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;
// 1000005
int A[1000005];
int B[1000005];
int T[1000005];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B, B + N);
    T[0] = B[0];
    int idx = 1;

    for (int i = 1; i < N; i++) {
        if (T[idx-1] == B[i])
            continue;

        T[idx] = B[i];
        idx++;
    }

    for (int i = 0; i < N; i++) {
        cout << lower_bound(T, T + idx, A[i]) - T << " ";
    }

    cout << endl;
}