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

char A[12][6];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int res;

queue<pair<int, int>> Q;

void Tilt()
{
	for (int j = 0; j < 6; j++) {
		char temp[12];
		int idx = 0;

		for (int i = 0; i < 12; i++)
			if (A[11-i][j] != '.') {
				temp[idx] = A[11-i][j];
				idx++;
			}

		for (int i = 0; i < 12; i++) {
			if (i < idx) 
				A[11 - i][j] = temp[i];
			
			else
				A[11 - i][j] = '.';
		}
	}
}

bool BFS(int r, int c) {
	vector<pair<int, int>> temp;
	int V[12][6] = { 0 };


	char color = A[r][c];
	Q.push({ r,c });
	V[r][c] = 1;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		temp.push_back({ cur.X, cur.Y });

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
				continue;

			if (A[nx][ny] == color && V[nx][ny] == 0) {
				Q.push({ nx,ny });
				V[nx][ny] = 1;
			}
		}
	}

	if (temp.size() < 4)
		return false;

	for (auto T : temp) {
		A[T.X][T.Y] = '.';
	}

	return true;
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> A[i][j];


	while (true) {
		int cnt = 0;

		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++) {
				if (A[i][j] == '.')
					continue;

				if (BFS(i, j)) {
					cnt++;
				}
			}

		if (cnt == 0)
			break;

		Tilt();
		res++;
	}

	cout << res << endl;
}