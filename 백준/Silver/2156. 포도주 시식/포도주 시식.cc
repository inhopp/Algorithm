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

long long A[3][10005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, v;
	cin >> N >> A[1][1];
	 
	for (int i = 2; i <= N; i++) {
		cin >> v;
		A[0][i] = max({A[0][i-1], A[1][i - 1], A[2][i - 1]});
		A[1][i] = A[0][i - 1] + v;
		A[2][i] = A[1][i - 1] + v;
	}

	cout << max({ A[0][N], A[1][N], A[2][N] }) << endl;
}