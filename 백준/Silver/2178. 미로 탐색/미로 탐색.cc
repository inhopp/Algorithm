#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define X first
#define Y second

int A[101][101];
int V[101][101];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < n; j++)
			A[i][j] = s[j] - '0';
	}

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] == 0 or V[i][j] > 0)
				continue;

			queue<pair<int, int>> Q;
			Q.push({ i, j });
			V[i][j]++;

			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx >= 0 and nx < m and ny >= 0 and ny < n)
					{
						if (A[nx][ny] == 1 and V[nx][ny] == 0)
						{
							Q.push({ nx, ny });
							V[nx][ny] = V[cur.X][cur.Y] + 1;

							if (nx == m - 1 and ny == n - 1)
							{
								cout << V[nx][ny];
								return 0;
							}
						}
					}
				}
			}
		}
	}
}