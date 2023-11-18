#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define X first
#define Y second

stack<pair<long long, long long>> A;
long long B[80000];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> B[i];

	long long res = 0;
	A.push({ 1000000001, 0 });

	for (int i = 0; i < n; i++)
	{
		int v = B[n - 1 - i];

		while (A.top().X < v)
			A.pop();

		res += (i - A.top().Y);
		A.push({ v, i + 1 });
	}

	cout << res;
}