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

int P[100002];
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

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		V.push_back({ cost,x,y });
	}

	fill(P + 1, P + N + 1, -1);
	sort(V.begin(), V.end());

	long long answer = 0;
	int idx = 0, cnt = 0, mx = -1;

	while (cnt < N - 1) {
		int cost, x, y;
		tie(cost, x, y) = V[idx++];

		if (!uniFind(x, y))
			continue;

		answer += cost;
		cnt++;
		mx = max(mx, cost);
	}

	answer -= mx;
	cout << answer << endl;

	return 0;
}