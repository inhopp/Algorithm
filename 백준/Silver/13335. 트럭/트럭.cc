#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int n, w, L;
deque<int> T;
deque<int> B;
deque<int> A;
int t, cnt;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> L;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		T.push_back(t);
	}

	for (int i = 0; i < w; i++)
		B.push_back(0);

	while (A.size() < n)
	{
		cnt++;

		if (B.front() > 0) A.push_back(B.front());
		B.pop_front();

		if (T.empty()) B.push_back(0);

		else
		{
			int sum = 0;
			for (int i = 0; i < w-1; i++)
				sum += B[i];

			if (sum + T.front() > L)
				B.push_back(0);

			else
			{
				B.push_back(T.front());
				T.pop_front();
			}

		}
	}

	cout << cnt << '\n';
}