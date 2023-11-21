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

	string str;
	cin >> str;

	stack<char> S;

	int sum = 0;
	int num = 1;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			num *= 2;
			S.push(str[i]);
		}

		else if (str[i] == '[')
		{
			num *= 3;
			S.push(str[i]);
		}

		else if (str[i] == ')')
		{
			if (S.empty() or S.top() != '(')
			{
				cout << 0;
				return 0;
			}

			if (str[i-1] == '(')
				sum += num;

			S.pop();
			num /= 2;
		}

		else
		{
			if (S.empty() or S.top() != '[')
			{
				cout << 0;
				return 0;
			}

			if (str[i - 1] == '[')
				sum += num;

			S.pop();
			num /= 3;
		}
	}

	if (S.empty())
		cout << sum;
	else
		cout << 0;
}