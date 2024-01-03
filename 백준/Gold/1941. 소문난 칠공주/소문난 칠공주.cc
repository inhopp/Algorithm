#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

char A[5][5];
int B[25];
int cnt;

int Board[5][5];
int V[5][5];
#define X first
#define Y second
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> Q;

bool check()
{
	int size = 0;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (Board[i][j] == 0 || V[i][j] == 1) continue;

			Q.push({ i,j });
			V[i][j] = 1;
			size++;

			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
					if (Board[nx][ny] == 0 || V[nx][ny] == 1) continue;

					Q.push({ nx, ny });
					V[nx][ny] = 1;
				}
			}
		}

	for (int i = 0; i < 5; i++)
		fill(V[i], V[i] + 5, 0);

	if (size > 1) return false;
	else return true;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> A[i][j];

	for (int i = 0; i < 25; i++)
	{
		if (i > 17)
			B[i] = 1;
		else
			B[i] = 0;
	}

	do {
		int sum = 0;

		for (int i = 0; i < 25; i++)
		{
			int r = i / 5;
			int c = i % 5;

			Board[r][c] = B[i];
		}

		if (!check()) continue;

		for (int i = 0; i < 25; i++)
		{
			int r = i / 5;
			int c = i % 5;

			if (B[i] == 1 && A[r][c] == 'S')
				sum++;
		}

		if (sum >= 4)
			cnt++;

	} while (next_permutation(B, B + 25));

	cout << cnt;
}