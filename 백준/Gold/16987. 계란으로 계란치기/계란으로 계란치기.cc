#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int N;
int S[8];
int W[8];
int cnt, mx;
vector<int> V;

void func(int state)
{
	if (state == N)
	{
		mx = max(mx, cnt);
		return;
	}

	if (S[state] <= 0 || cnt == N-1)
	{
		func(state + 1);
		return;
	}
		

	for (int i = 0; i < N; i++)
	{
		if (i == state || S[i] <= 0)
			continue;

		S[state] -= W[i];
		S[i] -= W[state];

		if (S[state] <= 0) cnt++;
		if (S[i] <= 0) cnt++;

		func(state+1);

		if (S[state] <= 0) cnt--;
		if (S[i] <= 0) cnt--;

		S[state] += W[i];
		S[i] += W[state];
	}

}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> S[i] >> W[i];

	func(0);

	cout << mx;
}