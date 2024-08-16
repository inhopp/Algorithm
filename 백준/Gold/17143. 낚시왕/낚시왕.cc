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

tuple<int, int, int> A[102][102];
tuple<int, int, int> B[102][102];

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

int R, C, M, r, c, s, d, z, ns, nd, nz, res;

int Fishing(int pos)
{
	int sz = 0;

	for (int i = 0; i < R; i++) {
		tie(s, d, z) = A[i][pos];

		if (z > 0) {
			sz = z;
			A[i][pos] = { 0,0,0 };
			break;
		}
	}

	return sz;
}

void Move()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			tie(s, d, z) = A[i][j];
			
			if (z == 0)
				continue;

			int nr = i;
			int nc = j;

			int cur_s = s;
			int cur_d = d;

			while (cur_s > 0) {
				if (cur_d == 1) {
					int tmp_s = min(nr, cur_s);
					nr -= tmp_s;
					cur_s -= tmp_s;

					if (nr == 0)
						cur_d = 2;
				}

				else if (cur_d == 2) {
					int tmp_s = min(R - 1 - nr, cur_s);
					nr += tmp_s;
					cur_s -= tmp_s;

					if (nr == R-1)
						cur_d = 1;
				}

				else if (cur_d == 3) {
					int tmp_s = min(C - 1 - nc, cur_s);
					nc += tmp_s;
					cur_s -= tmp_s;

					if (nc == C-1)
						cur_d = 4;
				}

				else {
					int tmp_s = min(nc, cur_s);
					nc -= tmp_s;
					cur_s -= tmp_s;

					if (nc == 0)
						cur_d = 3;
				}
			}

			tie(ns, nd, nz) = B[nr][nc];

			if (nz < z)
				B[nr][nc] = { s,cur_d,z };
		}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			A[i][j] = B[i][j];
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		A[r - 1][c - 1] = { s,d,z };
	}

	int pos = 0;
	
	while (pos < C) {
		res += Fishing(pos);
		Move();
		pos++;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				B[i][j] = { 0,0,0 };
	}

	cout << res << endl;
}