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

int P[10002];
vector<tuple<int, int, int>> G;

long long answer;

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

	int N, E;
	cin >> N >> E;

	fill(P + 1, P + N + 1, -1);
	
	while (E--) {
		int A, B, C;
		cin >> A >> B >> C;
		G.push_back({ C,A,B });
	}

	sort(G.begin(), G.end());

	int idx = 0, cnt = 0;
	while (cnt < N-1) {
		int v, x, y;
		tie(v, x, y) = G[idx++];

		if (!uniFind(x, y))
			continue;

		answer += v;
		cnt++;
	}

	cout << answer << endl;

	return 0;
}