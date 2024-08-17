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
// 51
int A[51][51];
int B[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> C;

int N, M, T, res;

void Diffusion()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (A[i][j] > 0) {
				int v = A[i][j] / 5;
				int cnt = 0;

				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
						continue;

					if (nx == C[0].X && ny == 0)
						continue;

					if (nx == C[1].X && ny == 0)
						continue;

					B[nx][ny] += v;
					cnt++;
				}

				B[i][j] += A[i][j] - cnt * v;
			}
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = B[i][j];
}

void Circulation()
{
	for (int i = C[0].X - 1; i > 0; i--)
		A[i][0] = A[i - 1][0];
	
	for (int j = 0; j < M - 1; j++)
		A[0][j] = A[0][j + 1];

	for (int i = 0; i < C[0].X; i++)
		A[i][M-1] = A[i + 1][M-1];

	for (int j = M - 1; j > 0; j--)
		A[C[0].X][j] = A[C[0].X][j - 1];

	for (int i = C[1].X + 1; i < N - 1; i++)
		A[i][0] = A[i + 1][0];

	for (int j = 0; j < M - 1; j++)
		A[N - 1][j] = A[N - 1][j + 1];

	for (int i = N - 1; i > C[1].X; i--)
		A[i][M - 1] = A[i-1][M - 1];

	for (int j = M - 1; j > 0; j--)
		A[C[1].X][j] = A[C[1].X][j - 1];
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];

			if (A[i][j] == -1) {
				A[i][j] = 0;
				C.push_back({ i,j });
			}
		}

	while (T--) {
		Diffusion();
		Circulation();

		for (int i = 0; i < N; i++)
			fill(B[i], B[i] + M, 0);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (A[i][j] > 0)
				res += A[i][j];

	cout << res << endl;
}