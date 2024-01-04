#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int N, M, K;
int R, C;

int note[40][40];
int sticker[10][10];
int temp[10][10];

void rotate()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			temp[i][j] = sticker[i][j];

	for (int i = 0; i < C; i++)
		for (int j = 0; j < R; j++)
			sticker[i][j] = temp[R - 1 - j][i];

	swap(R, C);
}

bool check(int x, int y)
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (note[x + i][y + j] == 1 && sticker[i][j] == 1) return false;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (sticker[i][j] == 1)
				note[x + i][y + j] = 1;

	return true;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	while (K--)
	{
		cin >> R >> C;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> sticker[i][j];


		bool flag = false;
		for (int rot = 0; rot < 4; rot++)
		{
			for (int i = 0; i <= N-R; i++)
			{
				if (flag) break;
				for (int j = 0; j <= M-C; j++)
				{
					if (check(i, j))
					{
						flag = true;
						break;
					}
				}
			}

			if (flag) break;
			rotate();
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (note[i][j] == 1) cnt++;

	cout << cnt;
}