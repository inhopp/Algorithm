#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int V[1000001];

queue<int> Q;
int F, S, G, U, D;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;

	Q.push(S);
	V[S] = 1;

	int dx[2] = { U, -D };

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		if (cur == G)
		{
			cout << V[cur]-1;
			return 0;
		}

		for (int dir = 0; dir < 2; dir++)
		{
			int nx = cur + dx[dir];

			if (nx <= 0 || nx > F) continue;
			if (V[nx] > 0) continue;

			Q.push(nx);
			V[nx] = V[cur] + 1;
		}
	}

	cout << "use the stairs";
}