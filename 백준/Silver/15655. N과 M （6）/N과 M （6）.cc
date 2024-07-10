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
vector<int> V;
int N, M;

void func(int n, int s)
{
	if (s == M + 1) {
		for (int i = 1; i <= M; i++) {
			cout << B[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = n; i <= N; i++) {
		B[s] = A[i];
		func(i + 1, s + 1);
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int v;
	for (int i = 0; i < N; i++) {
		cin >> v;
		V.push_back(v);
	}

	sort(V.begin(), V.end());

	for (int i = 0; i < N; i++) {
		A[i + 1] = V[i];
	}

	func(1, 1);
}