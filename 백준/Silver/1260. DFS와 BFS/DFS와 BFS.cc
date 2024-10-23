#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

vector<int> A[1002];
int V[1002];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		A[u].push_back(v);
		A[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
		sort(A[i].begin(), A[i].end());

	stack<int> S;
	S.push(K);

	while (!S.empty()) {
		int cur = S.top();
		S.pop();

		if (V[cur] == 1)
			continue;

		V[cur] = 1;
		cout << cur << " ";

		for (int i = 0; i < A[cur].size(); i++) {
			int nxt = A[cur][A[cur].size() - 1 - i];

			if (V[nxt] == 1)
				continue;

			S.push(nxt);
		}
	}
	cout << endl;
	fill(V, V + N + 1, 0);

	queue<int> Q;
	Q.push(K);
	V[K] = 1;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		cout << cur << " ";

		for (int a : A[cur]) {
			if (V[a] == 1)
				continue;

			Q.push(a);
			V[a] = 1;
		}
	}
	cout << endl;
}