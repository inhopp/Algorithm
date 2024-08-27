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

long long A[100];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	A[0] = 0;
	A[1] = 1;

	for (int i = 2; i <= N; i++) {
		A[i] = A[i - 2] + A[i - 1];
	}

	cout << A[N] << endl;
}