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

int P[1000005];

int find(int x)
{
	while (P[x] > 0)
		x = P[x];

	return x;
}

void uniFind(int u, int v)
{
	int r1 = find(u);
	int r2 = find(v);

	if (r1 == r2)
		return;

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

	return;
}

void Check(int u, int v)
{
	if (find(u) == find(v))
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

	return;
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N, K, M;
	int u, v, idx = 1;

	cin >> T;

	while (T--) {
		cin >> N >> K;

		fill(P + 1, P + N + 1, -1);

		while (K--) {
			cin >> u >> v;
			uniFind(u, v);
		}

		cin >> M;
		cout << "Scenario " << idx << ":\n";

		while (M--) {
			cin >> u >> v;
			Check(u, v);
		}

		cout << "\n";
		idx++;
	}
}