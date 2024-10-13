#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int A[1000005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N, mx;
	cin >> T;

	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];

		long long ans = 0;

		int mx = A[N - 1];

		for (int i = N - 2; i >= 0; i--) {
			if (A[i] > mx) {
				mx = A[i];
			}

			// A[i]<=mx
			ans += (mx - A[i]);
		}

		cout << ans << endl;
	}
}