#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define Y first
#define X second

int board[100][100];
int V[100][100];

int cnt;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<int> areas;
queue<pair<int, int>> Q;

int m, n, k;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;

	while (k--)
	{
		int min_x, min_y, max_x, max_y;
		cin >> min_x >> min_y >> max_x >> max_y;
		
		for (int x = min_x; x < max_x; x++)
			for (int y = m - max_y; y < m - min_y; y++)
				board[y][x] = 1;
	}

	for (int y = 0; y < m; y++)
		for (int x = 0; x < n; x++)
		{
			if (board[y][x] == 1) continue;

			Q.push({ y, x });
			board[y][x] = 1;
			V[y][x] = 1;

			cnt++;
			int area = 1;

			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int ny = cur.Y + dy[dir];
					int nx = cur.X + dx[dir];

					if (ny<0 || ny>=m || nx<0 || nx>=n) continue;
					if (board[ny][nx] == 1 || V[ny][nx] == 1) continue;

					area++;
					Q.push({ ny, nx });
					board[ny][nx] = 1;
					V[ny][nx] = 1;
				}
			}
			areas.push_back(area);
		}
	
	sort(areas.begin(), areas.end());

	cout << cnt << '\n';
	for (auto area : areas)
		cout << area << " ";
}


