#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <list>
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
		string s;
		cin >> s;
		
		list<char> L;
		auto cursor = L.begin();

		for (char c : s)
		{
			if (c == '<')
			{
				if (cursor != L.begin())
					cursor--;
			}

			else if (c == '>')
			{
				if (cursor != L.end())
					cursor++;
			}

			else if (c == '-')
			{
				if (cursor != L.begin())
				{
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			
			else
			{
				L.insert(cursor, c);
			}
		}

		for (auto c : L)
			cout << c;
		cout << '\n';
	}

}