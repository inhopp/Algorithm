#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void parse(string& temp, deque<int>& dq)
{
	int cur = 0;

	for (int i = 1; i+1 < temp.size(); i++)
	{
		if (temp[i] == ',')
		{
			dq.push_back(cur);
			cur = 0;
		}

		else
			cur = 10 * cur + (temp[i] - '0');
	}

	if (cur != 0)
		dq.push_back(cur);
}

void print(deque<int> dq)
{
	cout << '[';

	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i];

		if (i != dq.size() - 1)
			cout << ',';
	}

	cout << "]\n";
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		deque<int> dq;
		int rev = 0;
		int n;
		string query, tmp;
		bool isWrong = false;

		cin >> query;
		cin >> n;
		cin >> tmp;
		parse(tmp, dq);

		for (char c : query)
		{
			if (c == 'R')
				rev = 1 - rev;

			else
			{
				if (dq.empty())
				{
					isWrong = true;
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

		if (isWrong)
			cout << "error\n";

		else
		{
			if (rev)
				reverse(dq.begin(), dq.end());

			print(dq);
		}
	}
}