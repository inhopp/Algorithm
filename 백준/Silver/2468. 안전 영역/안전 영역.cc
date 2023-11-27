#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define X first
#define Y second

int board[100][100];
int rain[100][100];
int V[100][100];

int n;
int mx;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue<pair<int, int>> Q;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	int height = 0;

	while (true)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				int v = board[i][j];
				rain[i][j] = (v > height) ? v : 0;
			}

		int cnt = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (rain[i][j] == 0 || V[i][j] == 1) continue;

				Q.push({ i,j });
				V[i][j] = 1;
				cnt++;
				
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (rain[nx][ny] == 0 || V[nx][ny] == 1) continue;

						Q.push({ nx, ny });
						V[nx][ny] = 1;
					}
				}
			}

		if (cnt == 0)
			break;

		if (cnt > mx)
			mx = cnt;


		height++;
		for (int i = 0; i < n; i++)
		{
			fill(rain[i], rain[i] + n, 0);
			fill(V[i], V[i] + n, 0);
		}
	}

	cout << mx;
}

