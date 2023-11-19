#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	queue<int> Q;

	while (n--)
	{
		string s;
		cin >> s;

		int v;
		if (s == "push")
		{
			cin >> v;
			Q.push(v);
		}

		else if (s=="pop")
		{
			if (Q.empty())
				v = -1;
			else
			{
				v = Q.front();
				Q.pop();
			}

			cout << v << '\n';
		}

		else if (s=="size")
			cout << Q.size() << '\n';

		else if (s=="empty")
		{
			if (Q.empty())
				v = 1;
			else
				v = 0;

			cout << v << '\n';
		}

		else if (s=="front")
		{
			if (Q.empty())
				v = -1;
			else
				v = Q.front();

			cout << v << '\n';
		}

		else // back
		{
			if (Q.empty())
				v = -1;
			else
				v = Q.back();

			cout << v << '\n';
		}
	}

}		