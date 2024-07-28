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
// 북 동 남 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt = 0; 

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, x, y, d;
	cin >> N >> M >> x >> y >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	while (true) {
		if (A[x][y] == 0) {
			A[x][y] = -1;
			cnt++;
		}

		bool flag = false;
		
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;

			if (A[x + dx[d]][y + dy[d]] == 0) {
				x += dx[d];
				y += dy[d];
				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		if (A[x - dx[d]][y - dy[d]] == 1)
			break;

		x -= dx[d];
		y -= dy[d];
	}

	cout << cnt << endl;
}