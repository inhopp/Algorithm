#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int C[21];
int V[21][10001];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N, M;
	cin >> T;

	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> C[i];
			V[i][0] = 1;
		}
		cin >> M;


		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j < C[i]; j++)
				V[i][j] = V[i - 1][j];

			for (int j = C[i]; j <= M; j++)
				V[i][j] = V[i][j - C[i]] + V[i - 1][j];
		}

		cout << V[N][M] << "\n";

		for (int i = 1; i <= N; i++)
			fill(V[i], V[i] + M, 0);
	}
}