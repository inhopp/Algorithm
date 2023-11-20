#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		string s;
		int n;
		string x;
		bool error = false;

		cin >> s >> n >> x;

		deque<int> dq;

		
		string temp = "";
		for (char c : x)
		{
			if (c == '[')
				continue;

			else if (c >= '0' && c <= '9')
				temp += c;

			else if (c == ',')
			{
				dq.push_back(stoi(temp));
				temp = "";
			}

			else // ]
			{
				if (temp == "")
					continue;
				else
				{
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
		}

		int rev = 0;

		for (char c : s)
		{
			if (c == 'R')
			{
				rev = 1 - rev;
			}

			else // D
			{
				if (dq.empty())
				{
					error = true;
					break;
				}

				else
				{
					if (!rev)
						dq.pop_front();

					else
						dq.pop_back();
				}
			}
		}

		if (error)
			cout << "error\n";

		else
		{
			cout << '[';
			for (int i = 0; i < dq.size(); i++)
			{
				if (!rev)
					cout << dq[i];
				else
					cout << dq[dq.size() - 1 - i];

				if (i < dq.size() - 1)
					cout << ',';
			}
			cout << ']' << '\n';
		}
	}
}