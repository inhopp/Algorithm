#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define X first
#define Y second

stack<pair<int, int>> A;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	A.push({ 100000000,0 });
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;

		while (A.top().X < v)
			A.pop();

		cout << A.top().Y << " ";
		A.push({ v, i+1 });
	}

}