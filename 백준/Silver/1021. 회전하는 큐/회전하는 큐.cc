#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	deque<int> dq;

	for (int i = 1; i < n + 1; i++)
		dq.push_back(i);

	int cnt = 0;

	while (m--)
	{
		int v;
		cin >> v;

		int idx = 0;
		for (auto k : dq)
		{
			if (k == v)
				break;
			else
				idx++;
		}

		if (idx <= (dq.size() - 1) / 2)
		{
			for (int i = 0; i < idx; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}

			cnt += idx;
			dq.pop_front();
		}

		else
		{
			for (int i = 0; i < dq.size() - idx; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}

			cnt += (dq.size() - idx);
			dq.pop_front();
		}
	}

	cout << cnt;
}