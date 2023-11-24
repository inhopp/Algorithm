#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define X first
#define Y second

char board[100][100];
char board_weak[100][100];

queue<pair<int, int>> Q;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;

			board[i][j] = c;

			if (c == 'G')
				c = 'R';

			board_weak[i][j] = c;
		}

	int cnt = 0;
	int cnt_weak = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != '\0')
			{
				char color = board[i][j];

				Q.push({ i, j });
				board[i][j] = '\0';

				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] != color) continue;

						Q.push({ nx, ny });
						board[nx][ny] = '\0';
					}
				}
				cnt++;
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (board_weak[i][j] != '\0')
			{
				char color = board_weak[i][j];

				Q.push({ i, j });
				board_weak[i][j] = '\0';

				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board_weak[nx][ny] != color) continue;

						Q.push({ nx, ny });
						board_weak[nx][ny] = '\0';
					}
				}
				cnt_weak++;
			}
		}
	cout << cnt << " " << cnt_weak;
}