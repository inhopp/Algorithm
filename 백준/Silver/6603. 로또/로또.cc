#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>0
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int k;
int N[13];
int arr[6];

void func(int state, int index)
{
	if (state == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << arr[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = index; i < k; i++)
	{
		arr[state] = N[i];
		func(state + 1, i + 1);
	}
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		cin >> k;
		if (k == 0)
			return 0;

		for (int i = 0; i < k; i++)
			cin >> N[i];

		func(0, 0);
		cout << "\n";
	}
}