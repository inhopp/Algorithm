#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int A[1001][1001];
int B[1001][1001];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int mx = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		for (int j = 1; j <= m; j++)
			A[i][j] = s[j - 1] - '0';
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (A[i][j] == 0) B[i][j] = 0;
			else
			{
				B[i][j] = min(min(B[i - 1][j - 1], B[i - 1][j]), B[i][j - 1]) + 1;
				mx = max(mx, B[i][j]);
			}
		}

	cout << mx*mx << "\n";
}