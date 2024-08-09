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
int B[4];
int P[12];

int N, mx = -1000000000, mn = 1000000000;

int calc()
{
	int res = A[0];

	for (int i = 0; i < N - 1; i++) {
		int post = A[i + 1];
		int opt = P[i];

		if (opt == 0) {
			res += post;
		}

		else if (opt == 1) {
			res -= post;
		}

		else if (opt == 2) {
			res *= post;
		}

		else {
			res /= post;
		}
	}

	return res;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	// + - * %
	for (int i = 0; i < 4; i++)
		cin >> B[i];

	int N1 = B[0], N2 = B[0] + B[1], N3 = B[0] + B[1] + B[2], N4 = B[0] + B[1] + B[2] + B[3];

	for (int i = N1; i < N2; i++)
		P[i] = 1;

	for (int i = N2; i < N3; i++)
		P[i] = 2;

	for (int i = N3; i < N4; i++)
		P[i] = 3;

	do {
		int res = calc();

		mx = max(mx, res);
		mn = min(mn, res);
	} while (next_permutation(P, P + N - 1));

	cout << mx << "\n" << mn << endl;
}