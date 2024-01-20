#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int D[500][500];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, val;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			cin >> D[0][0];
			continue;
		}

		for (int j = 0; j <= i; j++)
		{
			cin >> val;

			if (j == 0) D[i][j] = D[i - 1][0] + val;
			else if (j == i) D[i][j] = D[i - 1][j - 1] + val;
			else D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + val;
		}
	}

	vector<int> V;
	for (int i = 0; i < N; i++)
		V.push_back(D[N - 1][i]);
	sort(V.begin(), V.end());

	int mx = V.back();

	cout << mx << "\n";

}