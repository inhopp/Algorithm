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
int D[1500051];
int T, P;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int mx = 0;
	int idx = 1;

	while (N--)
	{
		cin >> T >> P;

		D[idx - 1 + T] = max(D[idx - 1 + T], mx + P);
		mx = max(mx, D[idx]);
		idx++;
	}

	cout << mx << "\n";
}