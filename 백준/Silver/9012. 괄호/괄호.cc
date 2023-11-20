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

	while (n--)
	{
		string a;
		cin >> a;

		stack<char> S;
		bool isWrong = false;

		for (char c : a)
		{
			if (c == '(')
				S.push(c);

			else // ')'
			{
				if (!S.empty() && S.top() == '(')
					S.pop();

				else
				{
					isWrong = true;
					break;
				}
			}
		}

		if (!isWrong and S.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}