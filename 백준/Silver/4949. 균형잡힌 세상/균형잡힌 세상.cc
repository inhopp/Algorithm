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

	while (true)
	{
		string s;
		getline(cin, s);

		if (s == ".")
			break;

		stack<char> st;
		bool isWorng = false;

		for (char c : s)
		{
			if (c == '[' or c == '(')
				st.push(c);

			else if (c == ']')
			{
				if (st.empty() or st.top() != '[')
				{
					isWorng = true;
					break;
				}

				else
					st.pop();
			}

			else if (c == ')')
			{
				if (st.empty() or st.top() != '(')
				{
					isWorng = true;
					break;
				}

				else
					st.pop();
			}
		}

		if (isWorng or !st.empty())
			cout << "no\n";
		else
			cout << "yes\n";
	}
}