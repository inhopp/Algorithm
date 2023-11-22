#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define X first
#define Y second

int A[500][500];
int V[500][500];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	int num = 0;
	int max_area = 0;

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] == 0 or V[i][j] == 1)
				continue;

			num++;
			queue<pair<int, int>> Q;
			Q.push({ i, j });
			V[i][j] = 1;
			int area = 0;

			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();

				area++;

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx >= 0 and nx < m and ny >= 0 and ny < n)
					{
						if (V[nx][ny] == 0 and A[nx][ny] == 1)
						{
							Q.push({ nx, ny });
							V[nx][ny] = 1;
						}
					}
				}
			}

			max_area = max(max_area, area);
		}

	cout << num << '\n';
	cout << max_area;
}