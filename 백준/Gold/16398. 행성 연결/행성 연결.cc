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

int P[1002];
int Cost[1002][1002];
vector<tuple<int, int, int>> V;

int find(int x)
{
	while (P[x] > 0)
		x = P[x];

	return x;
}

bool uniFind(int u, int v)
{
	int r1 = find(u);
	int r2 = find(v);

	if (r1 == r2)
		return false;

	if (P[r1] == P[r2]) {
		P[r1]--;
		P[r2] = r1;
	}

	else {
		if (P[r1] < P[r2])
			P[r2] = r1;

		else
			P[r1] = r2;
	}

	return true;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> Cost[i][j];

	fill(P + 1, P + N + 1, -1);

	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			V.push_back({ Cost[i][j], i, j });

	sort(V.begin(), V.end());

	long long answer = 0;
	int cnt = 0, idx = 0;

	while (cnt < N - 1) {
		int c, x, y;
		tie(c, x, y) = V[idx++];

		if (!uniFind(x, y))
			continue;

		answer += c;
		cnt++;
	}

	cout << answer << "\n";

	return 0;
}