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

int A[2005];
int D[2005][2005];

int N, M, S, E;

int check(int s, int e)
{
	for (int i = 0; i < e - s; i++) {
		if (A[s + i] != A[e - i])
			return 0;
	}

	return 1;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	for (int i = 1; i <= N; i++) {
		D[i][i] = 1;

		if (A[i - 1] == A[i])
			D[i - 1][i] = 1;
	}

	for (int i = N - 2; i > 0; i--) {
		for (int length = 2; length <= N - i; length++) {
			if (A[i] == A[i + length])
				D[i][i + length] = D[i + 1][i + length - 1];
		}
	}

	cin >> M;
	while (M--) {
		cin >> S >> E;
		cout << D[S][E] << "\n";
	}
}