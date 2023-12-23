#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>0
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
char cand[15];
char arr[15];

void func(int state, int index)
{
	if (state == L)
	{
		int cnt = 0;
		for (int i = 0; i < L; i++)
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				cnt++;
		}

		if (L - cnt < 2 || cnt < 1)
			return;

		for (int i = 0; i < L; i++)
			cout << arr[i];
		cout << "\n";

		return;
	}


	char temp = '0';
	for (int i = index; i < C; i++)
	{
		if (temp != cand[i])
		{
			arr[state] = cand[i];
			temp = arr[state];
			func(state + 1, i + 1);
		}
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> cand[i];

	sort(cand, cand + C);

	func(0, 0);
}