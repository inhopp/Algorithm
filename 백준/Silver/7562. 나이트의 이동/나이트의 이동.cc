#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define X first
#define Y second

int board[300][300];
int V[300][300];

int T, n, x, y, xx, yy;
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

queue<pair<int, int>> Q;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	
	while (T--)
	{
		cin >> n;
		cin >> x >> y;
		cin >> xx >> yy;

		// DFS
		Q.push({ x, y });
		V[x][y] = 1;

		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();

			if (cur.X == xx && cur.Y == yy)
			{
				cout << V[cur.X][cur.Y] - 1 << '\n';
				while (!Q.empty()) Q.pop();
				break;
			}
			
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny<0 || ny>=n) continue;
				if (V[nx][ny] > 0) continue;

				Q.push({ nx, ny });
				V[nx][ny] = V[cur.X][cur.Y] + 1;
			}
		}

		// Initialization
		for (int i = 0; i < n; i++)
		{
			fill(board[i], board[i] + n, 0);
			fill(V[i], V[i] + n, 0);
		}
	}
}