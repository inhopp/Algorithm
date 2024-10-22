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

priority_queue<int> pq;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, x;
	cin >> N;

	while (N--) {
		cin >> x;

		if (x == 0) {
			if (pq.empty())
				cout << 0 << "\n";

			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}

		else
			pq.push(x);
	}

	return 0;
}