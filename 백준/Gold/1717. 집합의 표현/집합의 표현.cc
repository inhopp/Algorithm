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

int A[1000005];
int N, M;

int find(int x)
{
	while (A[x] > 0)
		x = A[x];

	return x;
}

void uniFind(int u, int v)
{
	int r1 = find(u);
	int r2 = find(v);

	if (r1 == r2)
		return;

	if (A[r1] == A[r2]) {
		A[r1]--;
		A[r2] = r1;
	}

	else {
		if (A[r1] < A[r2])
			A[r2] = r1;

		else
			A[r1] = r2;
	}

	return;
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	fill(A + 1, A + N + 1, -1);

	while (M--) {
		int q, a, b;
		cin >> q >> a >> b;

		if (q == 0)
			uniFind(a, b);
			
		else {
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}