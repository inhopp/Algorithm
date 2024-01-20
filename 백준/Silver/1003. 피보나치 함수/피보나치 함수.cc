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

	int T, N;

	cin >> T;

	while (T--)
	{
		int zeros[41] = { 0, };
		int ones[41] = { 0, };

		cin >> N;

		zeros[0] = 1;
		ones[1] = 1;

		for (int i = 2; i <= N; i++)
		{
			zeros[i] = zeros[i - 2] + zeros[i - 1];
			ones[i] = ones[i - 2] + ones[i - 1];
		}

		cout << zeros[N] << " " << ones[N] << "\n";
	}
}