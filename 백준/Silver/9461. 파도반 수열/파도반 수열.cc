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

	long long B[102];
	B[1] = 1;
	B[2] = 1;
	B[3] = 1;

	deque<long long> Q;

	while (T--)
	{
		cin >> N;
		Q.push_back(N);
	}

	int mx=0;
	for (int q : Q)
		mx = max(mx, q);

	for (int i = 4; i <= mx; i++)
		B[i] = B[i - 2] + B[i - 3];

	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop_front();

		cout << B[idx] << "\n";
	}
}