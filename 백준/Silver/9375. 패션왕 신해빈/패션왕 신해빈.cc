#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <unordered_map>

using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		
		int ans = 1;
		unordered_map<string, int> M;

		while (N--) {
			string name, category;
			cin >> name >> category;

			if (M.find(category) == M.end())
				M[category] = 1;

			else
				M[category] += 1;
		}

		for (auto pair : M) {
			ans *= (pair.second + 1);
		}

		cout << ans - 1 << "\n";
	}
}