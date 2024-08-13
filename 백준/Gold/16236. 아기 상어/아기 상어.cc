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

int A[21][21];
int V[21][21];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

pair<int, int> pos;

int sz = 2, cnt = 0;
int N, v, res;

int BFS()
{
	queue<pair<int, int>> Q;
	Q.push(pos);
	V[pos.X][pos.Y] = 1;

	int mn = 500;
	vector<pair<int, int>> Cand;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		if (V[cur.X][cur.Y] >= mn)
			break;

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			if (A[nx][ny] > sz || V[nx][ny] > 0)
				continue;

			if (A[nx][ny] == 0 || A[nx][ny] == sz) {
				Q.push({ nx,ny });
				V[nx][ny] = V[cur.X][cur.Y] + 1;
			}

			else {
				V[nx][ny] = V[cur.X][cur.Y] + 1;
				Cand.push_back({ nx,ny });
				mn = V[nx][ny];
			}
			
		}
	}

	if (Cand.size() == 0)
		return 0;

	sort(Cand.begin(), Cand.end());
	pos = Cand[0];
	A[pos.X][pos.Y] = 0;

	return V[pos.X][pos.Y] - 1;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> v;

			if (v == 9)
				pos = { i,j };

			else
				A[i][j] = v;
		}

	while (true) {
		int n = BFS();

		if (n == 0)
			break;

		res += n;

		cnt++;
		if (cnt == sz) {
			sz++;
			cnt = 0;
		}

		for (int i = 0; i < N; i++)
			fill(V[i], V[i] + N, 0);
	}

	cout << res << endl;
}