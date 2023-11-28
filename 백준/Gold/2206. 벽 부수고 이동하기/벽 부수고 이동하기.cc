#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

#define X first
#define Y second

char board[1000][1000];
int dist[1000][1000][2];

int n, m, cur_x, cur_y, cur_z, res;
bool arrive = false;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue<tuple<int, int, int>> Q;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	Q.push({ 0,0,0 });
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;

	while (!Q.empty())
	{
		tie(cur_x, cur_y, cur_z) = Q.front();
		Q.pop();

		if (cur_x == n - 1 && cur_y == m - 1)
		{
			arrive = true;
			res = dist[cur_x][cur_y][cur_z];
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur_x + dx[dir];
			int ny = cur_y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == '1' && cur_z == 0 && dist[nx][ny][1] == 0)
			{
				Q.push({ nx, ny, 1 });
				dist[nx][ny][1] = dist[cur_x][cur_y][0] + 1;
			}

			if (board[nx][ny] == '0' && dist[nx][ny][cur_z] == 0)
			{
				Q.push({ nx, ny, cur_z });
				dist[nx][ny][cur_z] = dist[cur_x][cur_y][cur_z] + 1;
			}
			
		}
	}

	if (arrive)
		cout << res;
	else
		cout << -1;
}