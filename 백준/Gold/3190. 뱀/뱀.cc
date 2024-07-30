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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

deque<pair<int, int>> DQ;

int N, K, L, x, y, D;
char C;
int cnt, dir;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		A[x - 1][y - 1] = 1;
	}


	A[0][0] = -1;
	DQ.push_back({ 0,0 });
	auto head = DQ.back();
	auto tail = DQ.front();

	cin >> L;
	while (L--) {
		cin >> D >> C;

		while (cnt < D) {
			cnt++;

			auto head = DQ.back();
			int nx = head.X + dx[dir];
			int ny = head.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || A[nx][ny] == -1) {
				cout << cnt << endl;
				return 0;
			}

			if (A[nx][ny] == 0) {
				auto tail = DQ.front();
				A[tail.X][tail.Y] = 0;
				DQ.pop_front();
			}

			DQ.push_back({ nx,ny });
			A[nx][ny] = -1;
		}

		if (C == 'L') {
			dir = (dir + 3) % 4;
		}

		else {
			dir = (dir + 1) % 4;
		}
	}

	while (true) {
		cnt++;

		auto head = DQ.back();
		int nx = head.X + dx[dir];
		int ny = head.Y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || A[nx][ny] == -1) {
			cout << cnt << endl;
			return 0;
		}

		if (A[nx][ny] == 0) {
			auto tail = DQ.front();
			A[tail.X][tail.Y] = 0;
			DQ.pop_front();
		}

		DQ.push_back({ nx,ny });
		A[nx][ny] = -1;
	}
}