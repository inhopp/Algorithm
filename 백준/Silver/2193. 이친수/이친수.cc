#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	long long A[92];
	A[1] = 1;
	A[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		A[i] = A[i - 2] + A[i - 1];
	}

	cout << A[N] << "\n";
}