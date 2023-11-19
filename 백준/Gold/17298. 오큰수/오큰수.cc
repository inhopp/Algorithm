#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> S;
int A[1000001];
int res[1000001];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
	{
		int idx = n - 1 - i;
		int v = A[idx];

		while (!S.empty() && S.top() <= v)
			S.pop();

		if (S.empty())
			res[idx] = -1;
		else
			res[idx] = S.top();

		S.push(v);
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";

}		