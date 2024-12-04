#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <math.h>
#include <tuple>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define MX 0x3f3f3f3f

int D[102][102];
int P[102][102];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		fill(D[i] + 1, D[i] + N + 1, MX);
		D[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;

		if (cost < D[x][y]) {
			D[x][y] = min(D[x][y], cost);
			P[x][y] = y;
		}
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[i][k];
				}
			}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (D[i][j] == MX) D[i][j] = 0;
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (P[i][j] == 0) {
				cout << 0 << "\n";
				continue;
			}

			int cur = i;
			int nxt = P[i][j];

			vector<int> V;
			V.push_back(cur);
			V.push_back(nxt);

			while (nxt != j) {
				cur = nxt;
				nxt = P[cur][j];
				V.push_back(nxt);
			}

			cout << V.size() << " ";
			for (int v : V)
				cout << v << " ";
			cout << "\n";
		}
	}

	return 0;
}