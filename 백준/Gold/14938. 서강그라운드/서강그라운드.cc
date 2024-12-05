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

int W[102];
int D[102][102];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
		cin >> W[i]; 

	for (int i = 1; i <= N; i++) {
		fill(D[i] + 1, D[i] + N + 1, MX);
		D[i][i] = 0;
	}

	for (int i = 0; i < R; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;

		D[x][y] = cost;
		D[y][x] = cost;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	int answer = 0;

	for (int i = 1; i <= N; i++) {
		int temp = 0;
		
		for (int j = 1; j <= N; j++) {
			if (D[i][j] <= M)
				temp += W[j];
		}

		answer = max(answer, temp);
	}

	cout << answer << endl;

	return 0;
}