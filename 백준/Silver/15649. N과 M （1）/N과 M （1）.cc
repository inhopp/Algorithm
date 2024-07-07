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
int res[9];
int N, M;

void func(int s)
{
	if (s == M+1)
	{
		for (int i = 1; i <= M; i++)
			cout << res[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (A[i] == 1)
			continue;

		A[i] = 1;
		res[s] = i;
		func(s + 1);
		A[i] = 0;
	}
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(1);
}