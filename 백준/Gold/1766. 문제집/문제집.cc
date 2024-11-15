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
#include <unordered_set>
#include <unordered_map>

using namespace std;

int P[32005];
int indegree[32005];
vector<int> Graph[32005];
priority_queue<int, vector<int>, greater<int>> PQ;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		indegree[v]++;
		Graph[u].push_back(v);
	}

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			PQ.push(i);

		if (Graph[i].size() > 1)
			sort(Graph[i].begin(), Graph[i].end());
	}

	while (!PQ.empty()) {
		int cur = PQ.top();
		PQ.pop();
		cout << cur << " ";

		for (int i : Graph[cur]) {
			indegree[i]--;
			if (indegree[i] == 0)
				PQ.push(i);
		}
	}

	return 0;
}