#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

vector<int> A[1001];
int V[1001];
int ans;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int st, ed;
	for (int i = 0; i < M; i++) {
		cin >> st >> ed;
		A[st].push_back(ed);
		A[ed].push_back(st);
	}

	for (int i = 1; i <= N; i++) {
		if (V[i] == 1)
			continue;

		ans++;
		queue<int> Q;
		Q.push(i);

		while (!Q.empty()) {
			int pos = Q.front();
			Q.pop();

			for (int dest : A[pos]) {
				if (V[dest] == 1)
					continue;

				Q.push(dest);
				V[dest] = 1;
			}
		}
	}

	cout << ans << endl;
}