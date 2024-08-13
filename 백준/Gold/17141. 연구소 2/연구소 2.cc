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

int A[51][51];
int B[51][51];
int V[51][51];
int P[11];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> Q;
vector<pair<int, int>> Pos;
int N, M, mn=3000;

int BFS()
{
	int cnt;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		cnt = V[cur.X][cur.Y];

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;

			if (B[nx][ny] > 0)
				continue;

			B[nx][ny] = 2;
			Q.push({ nx,ny });
			V[nx][ny] = V[cur.X][cur.Y] + 1;
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (B[i][j] == 0)
				return -1;

	return cnt-1;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			
			if (A[i][j] == 2) {
				Pos.push_back({ i,j });
				A[i][j] = 0;
			}
		}

	fill(P + Pos.size() - M, P + Pos.size(), 1);
	bool flag = false;

	do {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				B[i][j] = A[i][j];

		for (int i = 0; i < Pos.size(); i++)
			if (P[i] == 1) {
				auto pos = Pos[i];

				B[pos.X][pos.Y] = 2;
				Q.push(pos);
				V[pos.X][pos.Y] = 1;
			}

		int cnt = BFS();

		if (cnt > -1) {
			flag = true;
			mn = min(mn, cnt);
		}

		for (int i = 0; i < N; i++)
			fill(V[i], V[i] + N, 0);
			
	} while (next_permutation(P, P + Pos.size()));

	if (!flag)
		cout << -1 << endl;

	else
		cout << mn << endl;
}