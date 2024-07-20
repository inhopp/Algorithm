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
int B[21][21];
int C[21];

int N, mx;

void rotate()
{
	int Temp[21][21];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Temp[i][j] = B[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			B[i][j] = Temp[N - 1 - j][i];
}

void move(int dir)
{
	while (dir--) rotate();

	for (int i = 0; i < N; i++) {
		fill(C, C + N, 0);
		int idx = 0;

		for (int j = 0; j < N; j++) {
			if (B[i][j] == 0)
				continue;

			if (C[idx] == 0) 
				C[idx] = B[i][j];

			else if (C[idx] == B[i][j]) {
				C[idx++] *= 2;
			}

			else {
				C[++idx] = B[i][j];
			}
		}

		for (int j = 0; j < N; j++)
			B[i][j] = C[j];
	}

}

int maximum()
{
	int mx = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (B[i][j] > mx)
				mx = B[i][j];
		}

	return mx;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	int total = 1 << 2 * 5;
	for (int temp = 0; temp < total; temp++) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				B[i][j] = A[i][j];

		int brute = temp;

		for (int i = 0; i < 5; i++) {
			int dir = brute % 4;
			brute /= 4;

			move(dir);
		}

		mx = max(mx, maximum());
	}

	cout << mx << endl;
}