#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

const int MX = 4000002;
vector<int> A(MX, 0);
vector<int> P;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i * i < MX; i++) {
		if (A[i] == 1)
			continue;

		for (int j = i * i; j < MX; j += i)
			A[j] = 1;
	}

	int N;
	cin >> N;

	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 2; i <= N; i++)
		if (A[i] == 0)
			P.push_back(i);

	int ans = 0;
	int st = 0, ed = 0;
	int sum = P[0];

	while (true) {
		if (sum == N)
			ans++;

		if (sum > N) {
			sum -= P[st];
			st++;
		}

		else {
			ed++;
			if (ed >= P.size())
				break;
			sum += P[ed];
		}
	}

	cout << ans << endl;
}