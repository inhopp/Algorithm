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

	int N, T, P;
	cin >> N;

	int D[21] = { 0, };
	int mx = 0;

	for (int i = 1; i <= N; i++)
	{
		cin >> T >> P;
		D[i - 1 + T] = max(D[i - 1 + T], mx + P);
		mx = max(mx, D[i]);
	}

	cout << mx << "\n";
}