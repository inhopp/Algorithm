#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

char Board[12][6];
int Visit[12][6];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

#define X first
#define Y second

queue<pair<int, int>> Q;
vector<pair<int, int>> temp;

int cnt;

int func(int x, int y)
{
	char color = Board[x][y];
	
	temp.push_back({ x, y });
	Q.push({ x, y });
	Visit[x][y] = 1;

	int size = 0;

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		size++;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (Board[nx][ny] != color || Visit[nx][ny] == 1) continue;

			Q.push({ nx, ny });
			Visit[nx][ny] = 1;
			temp.push_back({ nx,ny });
		}
	}

	if (size < 4)
	{
		temp.clear();
		return 0;
	}

	for (auto pos : temp)
		Board[pos.X][pos.Y] = '.';

	temp.clear();

	return size;
}

void tilt()
{
	char tiltTemp[12];
	
	for (int i = 0; i < 6; i++)
	{
		int idx = 0;
		fill(tiltTemp, tiltTemp + 12, '.');

		for (int j = 0; j < 12; j++)
		{
			if (Board[12 - 1 - j][i] == '.') continue;
			tiltTemp[idx++] = Board[12 - 1 - j][i];
		}

		for (int k = 0; k < 12; k++)
			Board[12 - 1 - k][i] = tiltTemp[k];
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> Board[i][j];

	while (true)
	{
		int chain = 0;

		for (int i = 0; i < 12; i++)
			fill(Visit[i], Visit[i] + 6, 0);

		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
			{
				if (Board[i][j] == '.' || Visit[i][j] == 1) continue;

				chain += func(i, j);
			}

		if (chain == 0) break;
		tilt();
		cnt++;
	}

	cout << cnt;
}