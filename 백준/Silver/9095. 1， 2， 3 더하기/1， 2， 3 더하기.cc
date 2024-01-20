#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, n;
	int D[11];

	D[0] = 0;
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	cin >> T;

	while (T--)
	{
		cin >> n;

		for (int i = 4; i <= n; i++)
			D[i] = D[i - 3] + D[i - 2] + D[i - 1];

		cout << D[n] << "\n";

		fill(D + 4, D + 11, 0);
	}
}