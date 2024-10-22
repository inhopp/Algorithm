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

priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, v;
	cin >> N;
	
	for (int i = 0; i < N * N; i++) {
		cin >> v;
		pq.push(v);

		if (pq.size() > N)
			pq.pop();
	}

	cout << pq.top() << endl;
}