#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

using ll = long long;
ll A, B, C;


ll POW(ll A, ll B, ll C)
{
	if (B == 1)
		return (A % C);

	ll val = POW(A, B / 2, C);
	val = val * val % C;

	if (B % 2 == 0)
		return val;

	return val * A % C;
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;
	cout << POW(A, B, C);
}