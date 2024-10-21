#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <unordered_map>
#include <map>

using namespace std;

unordered_map<string, vector<string>> g2m;
unordered_map<string, string> m2g;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	while (N--) {
		string group;
		int num;
		cin >> group >> num;

		vector<string> members;
		while (num--) {
			string member;
			cin >> member;

			members.push_back(member);
			m2g[member] = group;
		}

		sort(members.begin(), members.end());
		g2m[group] = members;
	}

	while (M--) {
		int question;
		string query;
		cin >> query >> question;

		if (question == 0) {
			auto M = g2m[query];

			for (string m : M) {
				cout << m << "\n";
			}
		}

		else {
			cout << m2g[query] << "\n";
		}
	}

	return 0;
}