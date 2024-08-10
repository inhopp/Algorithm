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

bool A[31][13];
int P[302];
vector<pair<int, int>> V;
int N, M, H, cnt;

bool Play()
{
	// i : 1 ~ N
	for (int i = 1; i <= N; i++) {
		int cur = i;

		for (int h = 0; h < H; h++) {
			if (A[h][cur - 1]) {
				cur -= 1;
				continue;
			}

			if (A[h][cur]) {
				cur += 1;
				continue;
			}
		}

		if (cur != i)
			return false;
	}

	return true;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	// 세로, 다리, 가로
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		A[r - 1][c] = true;
	}

	for (int i = 0; i < H; i++)
		for (int j = 1; j < N; j++) {
			if (A[i][j - 1] || A[i][j] || A[i][j + 1])
				continue;

			V.push_back({ i,j });
		}

	int sz = V.size();

	while (cnt < 4) {
		fill(P, P + sz, 0);
		fill(P + sz - cnt, P + sz, 1);

		do {
			bool flag;

			for (int i = 0; i < sz; i++) {
				if (P[i] == 1) 
					A[V[i].X][V[i].Y] = true;
			}

			flag = Play();

			for (int i = 0; i < sz; i++) {
				if (P[i] == 1)
					A[V[i].X][V[i].Y] = false;
			}

			if (flag) {
				cout << cnt << endl;
				return 0;
			}
		} while (next_permutation(P, P + sz));

		cnt++;
	}

	cout << -1 << endl;
}