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

int A[9][9];
int B[9][9];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> V0;
vector<pair<int, int>> V2;
queue<pair<int, int>> Q;

int P[65];
int N, M, mx;


void BFS()
{
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (B[nx][ny] == 0) {
				B[nx][ny] = 2;
				Q.push({ nx,ny });
			}
		}
	}
}

int Count()
{
	int cnt = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (B[i][j] == 0)
				cnt++;

	return cnt;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];

			if (A[i][j] == 0)
				V0.push_back({ i,j });

			else if (A[i][j] == 2)
				V2.push_back({ i,j });
		}
			
	for (int i = V0.size() - 3; i < V0.size(); i++)
		P[i] = 1;

	do {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				B[i][j] = A[i][j];

		for (int i = 0; i < V0.size(); i++) {
			if (P[i] == 1) {
				auto pos = V0[i];
				B[pos.X][pos.Y] = 1;
			}
		}

		for (auto pos : V2)
			Q.push(pos);

		BFS();
		mx = max(mx, Count());

	} while (next_permutation(P, P + V0.size()));

	cout << mx << endl;
}