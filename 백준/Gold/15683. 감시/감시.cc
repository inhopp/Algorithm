#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int N, M;
int Board[8][8];
int Board2[8][8];
int mn;

#define X first
#define Y second
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<pair<int, int>> V;

void update(int x, int y, int dir)
{
	dir %= 4;

	while (true)
	{
		x += dx[dir];
		y += dy[dir];

		if (x < 0 || x >= N || y < 0 || y >= M || Board2[x][y] == 6) return;
		if (Board2[x][y] != 0) continue;
		Board2[x][y] = 7;
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> Board[i][j];
			if (Board[i][j] > 0 && Board[i][j] < 6)
				V.push_back({ i,j });

			else if (Board[i][j] == 0)
				mn++;
		}

	int temp = 1;
	for (int i = 0; i < V.size(); i++)
		temp *= 4;

	for (int k = 0; k < temp; k++)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				Board2[i][j] = Board[i][j];

		int brute = k;

		for (int i = 0; i < V.size(); i++)
		{
			int x = V[i].X;
			int y = V[i].Y;

			int dir = brute % 4;
			brute /= 4;

			if (Board2[x][y] == 1)
				update(x, y, dir);
			
			else if (Board2[x][y] == 2)
			{
				update(x, y, dir);
				update(x, y, dir + 2);
			}

			else if (Board2[x][y] == 3)
			{
				update(x, y, dir);
				update(x, y, dir + 1);
			}

			else if (Board2[x][y] == 4)
			{
				update(x, y, dir);
				update(x, y, dir + 1);
				update(x, y, dir + 2);
			}

			else
			{
				update(x, y, dir);
				update(x, y, dir + 1);
				update(x, y, dir + 2);
				update(x, y, dir + 3);
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (Board2[i][j] == 0) cnt++;
		
		mn = min(mn, cnt);
	}

	cout << mn;
}