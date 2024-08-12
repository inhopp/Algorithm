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

int A[11][11]; // 현재 양분
int B[11][11]; // 리필 양분
deque<int> T[11][11];
queue<int> D[11][11];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int N, M, K, res;

void Spring()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (T[i][j].size() > 0) {
				sort(T[i][j].begin(), T[i][j].end());

				int sz = T[i][j].size();
				for (int k = 0; k < sz; k++) {
					int v = T[i][j].front();
					T[i][j].pop_front();

					if (A[i][j] >= v) {
						A[i][j] -= v;
						T[i][j].push_back(v+1);
					}

					else {
						D[i][j].push(v);
					}
				}
			}
		}
}

void Summer()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (D[i][j].size() > 0) {
				while (!D[i][j].empty()) {
					int v = D[i][j].front() / 2;
					D[i][j].pop();

					A[i][j] += v;
				}
			}
		}
}

void Fall()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (T[i][j].size() > 0) {
				for (int v : T[i][j]) {
					if (v % 5 != 0)
						continue;

					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;

						T[nx][ny].push_front(1);
					}
				}
			}
		}
}

void Winter()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] += B[i][j];
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> B[i][j];
			A[i][j] = 5;
		}

	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		T[x - 1][y - 1].push_back(z);
	}

	while (K--) {
		Spring();
		Summer();
		Fall();
		Winter();
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (T[i][j].size() > 0)
				res += T[i][j].size();
		
	cout << res << endl;
}