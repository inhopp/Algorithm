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

long long D[1005][10];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int j = 0; j < 10; j++)
		D[1][j] = 1;

	for (int i = 2; i <= N; i++) {
		D[i][9] = 1;

		for (int j = 8; j >= 0; j--) {
			D[i][j] = (D[i][j + 1] + D[i-1][j]) % 10007;
		}
	}

	int res = 0;
	for (int j = 0; j < 10; j++)
		res = (res + D[N][j]) % 10007;

	cout << res << endl;
}