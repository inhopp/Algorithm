#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define X first
#define Y second

int A[51][51];
int V[51][51];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> Q;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int m, n, k;
		cin >> m >> n >> k;

		int cnt = 0;

		while (k--)
		{
			int x, y;
			cin >> x >> y;
			
			A[x][y] = 1;
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (A[i][j] != 1 || V[i][j] == 1) continue;

				cnt++;
				Q.push({ i,j });
				V[i][j] = 1;

				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
						if (A[nx][ny] != 1 || V[nx][ny] == 1) continue;

						Q.push({ nx, ny });
						V[nx][ny] = 1;
					}
				}
			}
		}

		cout << cnt << "\n";
		
		for (int i = 0; i < m; i++)
		{
			fill(A[i], A[i] + n, 0);
			fill(V[i], V[i] + n, 0);
		}
	}

	return 0;
}