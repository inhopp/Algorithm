#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int A[10] = { 0, };
	int res = 0;

	while (n > 0)
	{
		A[n % 10]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 6 or i == 9)
			continue;

		else
			res = max(res, A[i]);
	}

	res = max(res, (A[6] + A[9] + 1) / 2);

	cout << res << endl;
}