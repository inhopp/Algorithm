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

int A[21];
int cnt;
int N, S;

void func(int s, int total)
{
	if (s == N + 1) {
		if (total == S)
			cnt++;
		return;
	}

	func(s + 1, total);
	func(s + 1, total + A[s]);
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	func(1, 0);

	if (S == 0) cnt--;
	cout << cnt << endl;
}