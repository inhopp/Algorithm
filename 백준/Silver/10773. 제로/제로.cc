#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
using namespace std;

int A[1000000];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int pos = 0;
	while(n--)
	{
		int v;
		cin >> v;

		if (v == 0)
		{
			if (pos > 0)
				pos--;
		}

		else
		{
			A[pos] = v;
			pos++;
		}
	}

	int res = 0;
	for (int i = 0; i < pos; i++)
		res += A[i];

	cout << res;
}