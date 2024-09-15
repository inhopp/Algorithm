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

int A[105];
long long D[10005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	D[0] = 1;
	
	for (int i = 0; i < N; i++)
		for (int j = A[i]; j <= K; j++)
			D[j] += D[j - A[i]];

	cout << D[K] << endl;
}