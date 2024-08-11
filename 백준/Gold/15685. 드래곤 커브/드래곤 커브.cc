#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
#include <math.h>

using namespace std;

#define X first
#define Y second

int A[101][101];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

pair<int, int> M;
int mx = -1, my = -1, res;

pair<int,int> Draw(int x, int y, int dir, int g)
{
	vector<pair<int, int>> V;
	A[x][y] = 1;
	V.push_back({ x,y });

	x += dx[dir];
	y += dy[dir];
	A[x][y] = 1;
	V.push_back({ x,y });

	while (g--) {
		int cur_x = V.back().X;
		int cur_y = V.back().Y;

		for (int i = V.size() - 2; i >= 0; i--) {
			int diff_x = V[i].X - cur_x;
			int diff_y = V[i].Y - cur_y;

			int new_x = cur_x + diff_y;
			int new_y = cur_y - diff_x;

			V.push_back({ new_x , new_y });
			A[new_x][new_y] = 1;
		}
	}

	int mx_x = -1, mx_y = 1;
	for (auto pos : V) {
		mx_x = max(mx_x, pos.X);
		mx_y = max(mx_y, pos.Y);
	}

	return { mx_x, mx_y };
}

int Counting(int R, int C)
{
	int cnt = 0;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (A[i][j] == 0 || A[i + 1][j] == 0 || A[i][j + 1] == 0 || A[i + 1][j + 1] == 0)
				continue;
			cnt++;
		}

	return cnt;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, x, y, d, g;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> y >> x >> d >> g;

		M = Draw(x, y, d, g);
		mx = max(mx, M.X);
		my = max(my, M.Y);
	}

	res = Counting(mx, my);

	cout << res << endl;
}