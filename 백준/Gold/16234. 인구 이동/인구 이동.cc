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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> Q;
vector<vector<pair<int, int>>> Pos;

int N, L, R, res;

bool Union()
{
	int num = 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (B[i][j] > 0) 
				continue;

			vector<pair<int, int>> V;

			B[i][j] = num;
			Q.push({ i,j });
			V.push_back({ i,j });

			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N || B[nx][ny]>0)
						continue;

					int diff = abs(A[cur.X][cur.Y] - A[nx][ny]);

					if (diff<L || diff>R)
						continue;

					B[nx][ny] = num;
					Q.push({ nx,ny });
					V.push_back({ nx,ny });
				}
			}

			if (V.size() == 1) {
				B[i][j] = 0;
				continue;
			}

			Pos.push_back(V);
			num++;
		}

	if (num == 1)
		return false;

	return true;
}

void Moving()
{
	for (auto pos : Pos) {
		int sum = 0;

		for (auto p : pos) 
			sum += A[p.X][p.Y];
		
		int d = sum / pos.size();

		for (auto p : pos)
			A[p.X][p.Y] = d;
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	while (true) {
		bool flag = Union();

		if (!flag) {
			break;
		}

		Moving();
		res++;

		for (int i = 0; i < N; i++)
			fill(B[i], B[i] + N, 0);

		Pos.clear();
	}

	cout << res << endl;
}