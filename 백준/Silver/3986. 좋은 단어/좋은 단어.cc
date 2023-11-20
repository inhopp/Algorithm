#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;

	while (n--)
	{
		string s;
		cin >> s;

		stack<char> st;

		for (char c : s)
		{
			if (!st.empty() && st.top() == c)
				st.pop();
			else
				st.push(c);
		}

		if (st.empty())
			cnt++;
	}

	cout << cnt;
}