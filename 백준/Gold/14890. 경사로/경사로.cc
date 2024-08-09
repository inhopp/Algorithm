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

int A[102][102];
int B[102];
int N, L, cnt;

bool check_row(int n)
{
	fill(B, B + N, 0);
	int prev = A[n][0];

	for (int i = 1; i < N; i++) {
		int cur = A[n][i];

		if (prev == cur)
			continue;

		if (abs(prev - cur) > 1)
			return false;

		if (prev > cur) {
			if (N - i < L)
				return false;

			for (int j = 0; j < L; j++) {
				if (A[n][i + j] != cur)
					return false;

				if (B[i + j] == 1)
					return false;

				B[i + j] = 1;
			}

			i += (L - 1);
			prev = A[n][i];
		}

		else {
			if (i < L)
				return false;

			for (int j = 1; j <= L; j++) {
				if (A[n][i - j] != prev)
					return false;

				if (B[i - j] == 1)
					return false;

				B[i - j] = 1;
			}

			prev = cur;
		}

	}

	return true;
}

bool check_col(int n)
{
	fill(B, B + N, 0);
	int prev = A[0][n];

	for (int i = 1; i < N; i++) {
		int cur = A[i][n];

		if (prev == cur)
			continue;

		if (abs(prev - cur) > 1)
			return false;

		if (prev > cur) {
			if (N - i < L)
				return false;

			for (int j = 0; j < L; j++) {
				if (A[i + j][n] != cur)
					return false;

				if (B[i + j] == 1)
					return false;

				B[i + j] = 1;
			}

			i += (L - 1);
			prev = A[i][n];
		}

		else {
			if (i < L)
				return false;

			for (int j = 1; j <= L; j++) {
				if (A[i - j][n] != prev)
					return false;

				if (B[i - j] == 1)
					return false;

				B[i - j] = 1;
			}

			prev = cur;
		}
	}

	return true;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	for (int i = 0; i < N; i++) {
		if (check_row(i)) 
			cnt++;

		if (check_col(i))
			cnt++;
	}

	cout << cnt << endl;
}