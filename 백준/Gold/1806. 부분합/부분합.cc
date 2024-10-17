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

	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	int mn = 0x7FFFFFFF;
	int sum = A[0], st = 0, ed = 0;

	while (true) {
		if (st > ed || ed > N) {
			break;
		}

		if (sum >= S) {
			mn = min(mn, ed - st + 1);
			sum -= A[st];
			st++;
		}

		else {
			ed++;
			sum += A[ed];
		}
	}

	if (mn == 0x7FFFFFFF)
		mn = 0;

	cout << mn << endl;
}