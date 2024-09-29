#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
#include <math.h>

using namespace std;

vector<pair<long long, long long>> V;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long s, e;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		V.push_back({ e,s });
	}

	sort(V.begin(), V.end());

	int cnt = 0, idx = 0;

	while (idx < N) {
		cnt++;

		e = V[idx].first;
		idx++;

		while (true) {
			if (idx >= N || V[idx].second >= e)
				break;

			idx++;
		}
	}

	cout << cnt << endl;
}