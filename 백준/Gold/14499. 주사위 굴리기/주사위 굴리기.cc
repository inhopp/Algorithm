#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

// up back right left front down
int dice[6];

// right, left, up, down
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int N, M, x, y, k, dir;
int Board[20][20];

void roll(int dir)
{
	int temp[6];

	for (int i = 0; i < 6; i++)
		temp[i] = dice[i];

	if (dir == 0)
	{
		dice[0] = temp[3];
		dice[2] = temp[0];
		dice[3] = temp[5];
		dice[5] = temp[2];
	}

	else if (dir == 1)
	{
		dice[0] = temp[2];
		dice[2] = temp[5];
		dice[3] = temp[0];
		dice[5] = temp[3];
	}

	else if (dir == 2)
	{
		dice[0] = temp[4];
		dice[1] = temp[0];
		dice[4] = temp[5];
		dice[5] = temp[1];
	}

	else
	{
		dice[0] = temp[1];
		dice[1] = temp[5];
		dice[4] = temp[0];
		dice[5] = temp[4];
	}
}

void update(int x, int y)
{
	if (Board[x][y] == 0)
		Board[x][y] = dice[5];

	else
	{
		dice[5] = Board[x][y];
		Board[x][y] = 0;
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> x >> y >> k;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Board[i][j];

	while (k--)
	{
		cin >> dir;
		dir--;

		if (x + dx[dir] < 0 || x + dx[dir] >= N || y + dy[dir] < 0 || y + dy[dir] >= M)
			continue;

		x += dx[dir];
		y += dy[dir];

		roll(dir);
		update(x, y);

		cout << dice[0] << "\n";
	}
}