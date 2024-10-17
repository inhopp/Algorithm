#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int A[100005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	int st = 0, ed = 0;
	int mn = 0x7FFFFFFF;

	while (true) {
		if (st > ed || ed >= N)
			break;

		int diff = abs(A[ed] - A[st]);

		if (diff >= M) {
			mn = min(mn, diff);
			st++;
		}

		else {
			ed++;
		}
	}

	cout << mn << endl;
}