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

int A[3][1002][32];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, W, v;
	cin >> T >> W;

	for (int t = 1; t <= T; t++) {
		cin >> v;

		A[1][t][0] = A[1][t - 1][0] + (v % 2);

		for (int w = 1; w <= W; w++) {
			if (t < w)
				break;

			if (v == 1) {
				A[1][t][w] = max(A[1][t - 1][w], A[2][t - 1][w - 1]) + 1;
				A[2][t][w] = max(A[1][t - 1][w - 1], A[2][t - 1][w]);
			}

			else {
				A[1][t][w] = max(A[1][t - 1][w], A[2][t - 1][w - 1]);
				A[2][t][w] = max(A[1][t - 1][w - 1], A[2][t - 1][w]) + 1;
			}
		}
	}

	int mx = 0;
	for (int w = 0; w <= W; w++) {
		mx = max({ mx, A[1][T][w], A[2][T][w] });
	}

	cout << mx << endl;
}