#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

#define big 1000000000

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	long long C[10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	long long temp[10] = { 0, };
	long long cnt = 0;

	if (N == 1)
	{
		cout << 9;
		return 0;
	}

	while (--N)
	{
		for (int i = 0; i < 10; i++)
			temp[i] = C[i];

		C[0] = temp[1] % big;
		for (int i = 1; i < 9; i++)
			C[i] = (temp[i - 1] + temp[i + 1]) % big;
		C[9] = temp[8] % big;
	}

	for (int i = 0; i < 10; i++)
		cnt = (cnt + C[i]) % big;

	cout << cnt % big;
}