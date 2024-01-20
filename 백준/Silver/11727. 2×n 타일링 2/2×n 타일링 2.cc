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

	int N;
	int D[1001];
	int mod = 10007;
	cin >> N;

	D[1] = 1;
	D[2] = 3;

	for (int i = 3; i <= N; i++)
		D[i] = (D[i - 1] + D[i - 2] * 2) % mod;

	cout << D[N] << "\n";
}