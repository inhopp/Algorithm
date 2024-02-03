#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int D[1001][1001];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++)
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j]) D[i + 1][j + 1] = D[i][j] + 1;

			else D[i + 1][j + 1] = max(D[i + 1][j], D[i][j + 1]);
		}

	cout << D[s1.size()][s2.size()] << "\n";
}