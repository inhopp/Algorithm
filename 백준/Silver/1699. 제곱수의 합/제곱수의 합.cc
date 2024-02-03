#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int N;
int D[100001];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		D[i] = i;

		for (int j = 1; j * j <= i; j++)
			D[i] = min(D[i], D[i - j * j] + 1);
	}

	cout << D[N] << "\n";
}