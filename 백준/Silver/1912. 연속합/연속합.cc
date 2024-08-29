#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
#include <math.h>

using namespace std;

long long A[100005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, v, mx = -1005;
	long long res = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> v;

		A[i] = A[i - 1] + v;

		if (A[i] < 0)
			A[i] = 0;

		mx = max(mx, v);
		res = max(res, A[i]);
	}

	if (res == 0)
		res = mx;

	cout << res << endl;
}