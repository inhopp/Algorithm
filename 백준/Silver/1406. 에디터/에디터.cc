#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int n;
	cin >> n;

	list<char> L;

	for (char c : s)
		L.push_back(c);

	auto cursor = L.end();

	
	char op;
	char x;

	while (n--)
	{
		cin >> op;

		if (op == 'P')
		{
			cin >> x;
			L.insert(cursor, x);
		}

		else if (op == 'L')
		{
			if (cursor != L.begin())
			{
				cursor--;
			}
		}

		else if (op == 'D')
		{
			if (cursor != L.end())
			{
				cursor++;
			}
		}

		// B
		else
		{
			if (cursor != L.begin())
			{
				cursor--;
				cursor = L.erase(cursor);
			}
		}
	}

	for (auto c : L) cout << c;
}