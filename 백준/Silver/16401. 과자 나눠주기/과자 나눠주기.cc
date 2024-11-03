#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <math.h>
#include <tuple>
#include <unordered_set>

using namespace std;

int A[1000005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	int st = 0;
	int ed = *max_element(A, A + N);

	while (st < ed) {
		int mid = (st + ed + 1) / 2;
		if (mid == 0) break;
		long long cnt = 0;

		for (int i = 0; i < N; i++) {
			cnt += A[i] / mid;
		}

		if (cnt < M) {
			ed = mid - 1;
		}

		else {
			st = mid;
		}
	}

	cout << st << endl;
}
