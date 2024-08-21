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

int A[301];
int B[2][301];
int N;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	B[0][1] = A[1];

	for (int i = 2; i <= N; i++) {
		B[0][i] = max(B[0][i - 2], B[1][i - 2]) + A[i];
		B[1][i] = B[0][i - 1] + A[i];
	}

	cout << max(B[0][N], B[1][N]) << endl;
}