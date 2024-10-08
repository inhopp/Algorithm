#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

 vector<int> A;
 vector<int> B;

 int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, val, ans = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val;
        A.push_back(val);
    }
    
    for (int i = 0; i < N; i++) {
        cin >> val;
        B.push_back(val);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < N; i++) {
        ans += A[i] * B[N - 1 - i];
    }

    cout << ans << endl;
}