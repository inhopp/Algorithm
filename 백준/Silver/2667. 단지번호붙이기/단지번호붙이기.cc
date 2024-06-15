#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define X first
#define Y second

int board[25][25];
int V[25][25];

int n;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue<pair<int, int>> Q;

int cnt;
vector<int> areas;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < n; j++)
			board[i][j] = s[j] - '0';
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0 || V[i][j] == 1) continue;

			cnt++;
			Q.push({ i,j });
			V[i][j] = 1;

			int area = 1;

			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == 0 || V[nx][ny] == 1) continue;

					area++;
					Q.push({ nx,ny });
					V[nx][ny] = 1;
				}
			}

			areas.push_back(area);
		}

	sort(areas.begin(), areas.end());

	cout << cnt << '\n';
	for (auto area : areas)
		cout << area << '\n';

}