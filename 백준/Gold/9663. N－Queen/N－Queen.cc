#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>0
#include <vector>
#include <stack>
#include <string>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> V;
int cnt = 0;
int N;

void func(int r, int c)
{
	for (auto v : V)
	{
		if (c == v.Y)
			return;

		else if ((v.X - r) == (v.Y - c))
			return;

		else if ((v.X - r) == -(v.Y - c))
			return;
	}

	V.push_back({ r,c });

	for (int i = 0; i < N; i++)
	{
		if (r + 1 >= N)
		{
			cnt++;
			break;
		}
		func(r + 1, i);
	}

	V.pop_back();
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int j = 0; j < N; j++)
		func(0, j);

	cout << cnt;
}