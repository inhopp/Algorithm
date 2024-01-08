#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int N, M;
int Map[50][50];
int Map2[50][50];
int Index[13];
int mn = 10000;

vector<pair<int, int>> V;
vector<pair<int, int>> V_temp;

#define X first
#define Y second

int func(int x, int y)
{
	int val = 10000;

	for (auto c : V_temp)
	{
		int cx = c.X;
		int cy = c.Y;

		int dist = abs(cx - x) + abs(cy - y);
		val = min(val, dist);
	}

	return val;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
			
			if (Map[i][j] == 2)
				V.push_back({ i,j });					
		}

	for (int i = 0; i < M; i++)
		Index[13 - 1 - i] = 1;

	do {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				Map2[i][j] = Map[i][j];

		int idx = -1;
		V_temp.clear();
		for (auto c : V)
		{
			idx++;
			if (Index[13 - 1 - idx] == 1)
			{
				V_temp.push_back({ c.X, c.Y });
				continue;
			}

			Map2[c.X][c.Y] = 0;
		}

		int dist = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (Map2[i][j] != 1) continue;
				
				dist += func(i, j);
			}

		mn = min(mn, dist);
	} while (next_permutation(Index, Index + 13));

	cout << mn;
}