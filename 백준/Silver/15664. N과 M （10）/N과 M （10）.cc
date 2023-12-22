#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>0
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


int n, m;
int N[8];
int arr[8];

void func(int state, int idx)
{
	if (state == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}

	int temp = 0;

	for (int i = idx; i < n; i++)
	{
		if (temp != N[i])
		{
			arr[state] = N[i];
			temp = N[i];

			func(state + 1, i + 1);
		}
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> N[i];

	sort(N, N + n);

	func(0, 0);
}