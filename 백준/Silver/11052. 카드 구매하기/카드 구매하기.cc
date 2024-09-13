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

long long D[10005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> D[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			D[i] = max(D[i - j] + D[j], D[i]);

	cout << D[N] << endl;
}