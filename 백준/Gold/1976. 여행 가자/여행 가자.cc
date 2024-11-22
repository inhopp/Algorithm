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

int P[205];
int T[1005];
int Temp[205];

int find(int x)
{
	while (P[x] > 0)
		x = P[x];

	return x;
}

void uniFind(int u, int v)
{
	int r1 = find(u);
	int r2 = find(v);

	if (r1 == r2)
		return;

	if (P[r1] == P[r2]) {
		P[r1]--;
		P[r2] = r1;
	}

	else {
		if (P[r1] < P[r2])
			P[r2] = r1;
		
		else
			P[r1] = r2;
	}

	return;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	fill(P + 1, P + N + 1, -1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> Temp[j];

		for (int j = i + 1; j <= N; j++) {
			if (Temp[j] == 1)
				uniFind(i, j);
		}
	}

	for (int i = 0; i < M; i++)
		cin >> T[i];

	int root = find(T[0]);
	bool flag = true;

	for (int i = 1; i < M; i++) {
		if (root == find(T[i]))
			continue;

		flag = false;
		break;
	}
	
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}