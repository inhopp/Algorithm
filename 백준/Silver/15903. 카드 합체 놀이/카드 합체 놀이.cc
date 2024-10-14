#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

priority_queue<long long, std::vector<long long>, std::greater<long long>> Q;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, val;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> val;
		Q.push(val);
	}

	while (M--) {
		long long v1 = Q.top();
		Q.pop();
		long long v2 = Q.top();
		Q.pop();

		Q.push(v1 + v2);
		Q.push(v1 + v2);
	}
	
	long long ans = 0;
	while (!Q.empty()) {
		ans += Q.top();
		Q.pop();
	}

	cout << ans << endl;
}