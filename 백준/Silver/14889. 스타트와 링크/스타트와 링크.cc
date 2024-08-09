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

int A[21][21];
int P[21];

int N, mn=100000000;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	for (int i = N / 2; i < N; i++)
		P[i] = 1;

	do {
		int S[2] = { 0,0 };

	for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j)
					continue;

				if (P[i] == P[j]) {
					S[P[i]] += A[i][j];
				}
			}
		}

		mn = min(mn, abs(S[0] - S[1]));

	} while (next_permutation(P, P + N));

	cout << mn << endl;
}