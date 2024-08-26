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

int A[1003];
int N;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	A[1] = 1;
	A[2] = 2;

	for (int i = 3; i <= N; i++) {
		A[i] = (A[i - 2] + A[i - 1]) % 10007;
	}

	cout << A[N] << endl;
}