#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int A[10005];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    int st = 0, ed = 0;
    int ans = 0, sum = A[0];

    while(true) {
        if (ed > N)
            break;

        if (sum == M) {
            ans++;

            sum -= A[st];
            st++;
        }

        else if (sum > M) {
            sum -= A[st];
            st++;
        }

        else {
            ed++;
            sum += A[ed];
        }
    }

    cout << ans << endl;
}