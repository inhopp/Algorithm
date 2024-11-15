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

int T[10005];
int indeg[10005];
vector<int> G[10005];
set<int> S;
vector<int> result;
int answer;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int t, n, p;
		cin >> t >> n;
		T[i] = t;

		for (int j = 0; j < n; j++) {
			cin >> p;
			G[p].push_back(i);
			indeg[i]++;
		}
	}

	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0)
			S.insert(i);

	while (result.size() < N) {
		answer++;

		vector<int> erase_temp;
		vector<int> insert_temp;

		for (int idx : S) {
			T[idx]--;
			if (T[idx] == 0) {
				erase_temp.push_back(idx);
				result.push_back(idx);

				for (int g : G[idx]) {
					indeg[g]--;
					if (indeg[g] == 0)
						insert_temp.push_back(g);
				}
			}
		}
		for (int e : erase_temp)
			S.erase(e);

		for (int i : insert_temp)
			S.insert(i);
	}

	cout << answer << endl;
}