#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define X first
#define Y second

int A[1000][1000];
int V[1000][1000];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

	int mx = 0;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (A[i][j] == 1)
				Q.push({ i, j });

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx >= 0 and nx < n and ny >= 0 and ny < m)
			{
				if (A[nx][ny] == 0 and V[nx][ny] == 0)
				{
					Q.push({ nx,ny });
					A[nx][ny] = 1;
					V[nx][ny] = V[cur.X][cur.Y] + 1;
					mx = max(mx, V[nx][ny]);
				}
			}
		}
	}


	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if (A[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

	cout << mx;
}