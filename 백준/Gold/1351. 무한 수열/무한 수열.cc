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

typedef long long ll;
unordered_map<ll, ll> D;
ll N;
int P, Q;

ll solve(ll x)
{
	if (x == 0)
		return 1;

	if (D[x])
		return D[x];

	D[x] = solve(x / P) + solve(x / Q);
	return D[x];
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> P >> Q;
	cout << solve(N) << endl;
}