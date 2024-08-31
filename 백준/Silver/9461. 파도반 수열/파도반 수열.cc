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

long long A[105];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	A[1] = 1;
	A[2] = 1;
	A[3] = 1;
	A[4] = 2;
	A[5] = 2;

	for (int i = 6; i <= 100; i++)
		A[i] = A[i - 1] + A[i - 5];

	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		cout << A[N] << endl;
	}
}