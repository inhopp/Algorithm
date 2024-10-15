#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int A[1005];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);

    int idx = N - 1;
    while (idx >= 0) {
        int val = A[idx];

        for (int i = idx - 1; i >= 0; i--) {
            val -= A[i];

            for (int j = i; j >= 0; j--) {
                val -= A[j];

                if (val > 0 && binary_search(A, A + N, val)) {
                    cout << A[idx] << endl;
                    return 0;
                }

                val += A[j];
            }

            val += A[i];
        }

        idx--;
    }
}