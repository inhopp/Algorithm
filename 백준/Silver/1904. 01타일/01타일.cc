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

long long D[1000005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= N; i++)
		D[i] = (D[i - 1] + D[i - 2]) % 15746;

	cout << D[N] << endl;
}