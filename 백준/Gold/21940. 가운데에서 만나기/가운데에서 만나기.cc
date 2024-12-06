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

int S[202];
int D[202][202];

int main(void)
{
	// freopen("input.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, K;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		fill(D[i] + 1, D[i] + N + 1, MX);
		D[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;

		D[x][y] = cost;
	}

	cin >> K;
	for (int i = 1; i <= K; i++)
		cin >> S[i];

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	vector<pair<int, int>> res;
	
	for (int i = 1; i <= N; i++) {
		int mx = 0;

		for (int j = 1; j <= K; j++)
			mx = max(mx, D[i][S[j]] + D[S[j]][i]);

		res.push_back({mx, i});
	}

	sort(res.begin(), res.end());

	int mn = res[0].first;

	for (auto r : res) {
		if (mn < r.first)
			break;

		cout << r.second << " ";
	}
	cout << endl;

	return 0;
}