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

int A[9];
int B[9];

int N, M, cnt;

void func(int n, int s)
{
	if (s == M + 1) {
		for (int i = 1; i <= M; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = n; i <= N; i++) {
		A[s] = i;
		func(i + 1, s + 1);
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	func(1, 1);
}