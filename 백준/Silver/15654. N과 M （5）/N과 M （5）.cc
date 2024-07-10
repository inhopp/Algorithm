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
int C[9];
vector<int> v;
int N, M;

void func(int s)
{
	if (s == M + 1) {
		for (int i = 1; i <= M; i++)
			cout << B[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (C[i] == 0) {
			C[i] = 1;
			B[s] = A[i];
			func(s + 1);
			C[i] = 0;
		}
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		A[i + 1] = v[i];
	}

	func(1);
}