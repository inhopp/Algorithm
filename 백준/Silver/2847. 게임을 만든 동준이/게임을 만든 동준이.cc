#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int A[105];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = N - 2; i >= 0; i--) {
		if (A[i] < A[i + 1])
			continue;

		while (A[i] >= A[i + 1]) {
			A[i] -= 1;
			ans++;
		}
	}

	cout << ans << endl;
}