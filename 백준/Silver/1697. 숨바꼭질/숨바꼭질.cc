#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dist[100002];
int n, k;


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >>  k;

	fill(dist, dist + 100001, -1);

	queue<int> Q;

	dist[n] = 0;
	Q.push(n);

	while (dist[k] == -1)
	{
		int cur = Q.front();
		Q.pop();

		for (int nx : {cur - 1, cur + 1, cur * 2})
		{
			if (nx < 0 || nx > 100000) continue;
			if (dist[nx] != -1) continue;
			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
	}

	cout << dist[k];
}