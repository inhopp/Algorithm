#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int D[1000001];
int x;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x;
	D[0] = 0;
	D[1] = 0;

	for (int i = 2; i <= x; i++)
	{
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1);
		if (i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1);
	}

	cout << D[x] << "\n";
}