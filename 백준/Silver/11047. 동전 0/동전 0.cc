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

int A[12];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, cnt = 0;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	for (int idx = N; idx > 0; idx--) {
		if (A[idx] > K)
			continue;

		while (A[idx] <= K) {
			K -= A[idx];
			cnt++;
		}

		if (K == 0)
			break;
	}

	cout << cnt << endl;
}