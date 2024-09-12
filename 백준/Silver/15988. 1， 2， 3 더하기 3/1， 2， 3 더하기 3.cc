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

	int T, N;
	cin >> T;

	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	while (T--) {
		cin >> N;
		for (int i = 4; i <= N; i++) {
			D[i] = (D[i - 1] + D[i - 2] + D[i - 3]) % 1000000009;
		}
		cout << D[N] << endl;
	}
}