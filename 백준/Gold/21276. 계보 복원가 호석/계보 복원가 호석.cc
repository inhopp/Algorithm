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

string name[1002];
unordered_map<string, int> name2idx;

int indegree[1002];
vector<int> Graph[1002];
vector<int> Child[1002];
vector<string> Root;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> name[i];

	sort(name, name + N);
	
	for (int i = 0; i < N; i++)
		name2idx[name[i]] = i;

	cin >> M;

	for (int i = 0; i < M; i++) {
		string u, v;
		cin >> u >> v;

		Graph[name2idx[v]].push_back(name2idx[u]);
		indegree[name2idx[u]]++;
	}

	// child
	for (int i = 0; i < N; i++) {
		if (Graph[i].size() == 0)
			continue;

		for (int idx : Graph[i]) {
			if (indegree[i] == indegree[idx] - 1)
				Child[i].push_back(idx);
		}

		sort(Child[i].begin(), Child[i].end());
	}

	for (int i = 0; i < N; i++) {
		if (indegree[i] > 0)
			continue;

		Root.push_back(name[i]);
	}

	cout << Root.size() << "\n";
	for (string s : Root)
		cout << s << " ";
	cout << "\n";

	for (int i = 0; i < N; i++) {
		cout << name[i] << " ";

		if (Child[i].size() == 0) {
			cout << 0 << "\n";
		}

		else {
			cout << Child[i].size() << " ";
			for (int idx : Child[i])
				cout << name[idx] << " ";
			cout << "\n";
		}
	}

	return 0;
}