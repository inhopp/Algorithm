#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
#include <math.h>

using namespace std;

long long D[41];
long long res = 1;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);
    
    D[0] = 1;
	D[1] = 1;
	D[2] = 2;
	for (int i = 3; i <= 40; i++)
		D[i] = D[i - 1] + D[i - 2];

	int N, M;
	cin >> N >> M;

	int prev = 1, idx;

	while (M--) {
		cin >> idx;
		res *= D[idx - prev];
		prev = idx + 1;
	}

	res *= D[N + 1 - prev];

	cout << res << endl;
}