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

long long F[2000005];
int offset = 1000002;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	F[offset] = 0;
	F[offset + 1] = 1;

	if (N >= 0) {
		for (int i = 2; i <= N; i++)
			F[offset + i] = (F[offset + i - 1] + F[offset + i - 2]) % 1000000000;
	}

	else {
		for (int i = -1; i >= N; i--)
			F[offset + i] = (F[offset + i + 2] - F[offset + i + 1]) % 1000000000;
	}

	if (F[offset + N] == 0) {
		cout << 0 << endl;
	}

	else if (F[offset + N] > 0) {
		cout << 1 << endl;
	}

	else {
		cout << -1 << endl;
		F[offset + N] *= -1;
	}

	cout << F[offset + N] << endl;
}