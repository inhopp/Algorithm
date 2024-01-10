#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

deque<int> D[4];
int k, idx, dir;
int cnt;

void Calc()
{
	if (D[0][0] == 1) cnt += 1;
	if (D[1][0] == 1) cnt += 2;
	if (D[2][0] == 1) cnt += 4;
	if (D[3][0] == 1) cnt += 8;
}

void rotate(int idx, int dir)
{
	if (dir == 1)
	{
		D[idx].push_front(D[idx].back());
		D[idx].pop_back();
	}

	else
	{
		D[idx].push_back(D[idx].front());
		D[idx].pop_front();
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	string val;
	for (int i = 0; i < 4; i++)
	{
		cin >> val;
		for (int j = 0; j < 8; j++)
			D[i].push_back(static_cast<int>(val[j]) - '0');
	}
	

	cin >> k;
	while (k--)
	{
		cin >> idx >> dir;

		idx--;

		int dirs[4] = {};
		dirs[idx] = dir;
		
		// check left direction
		int pos = idx;
		while (pos > 0 && D[pos][6] != D[pos-1][2])
		{
			dirs[pos - 1] = -dirs[pos];
			pos--;
		}

		// check right direction
		pos = idx;
		while (pos < 3 && D[pos][2] != D[pos + 1][6])
		{
			dirs[pos + 1] = -dirs[pos];
			pos++;
		}

		for (int i = 0; i < 4; i++)
			if (dirs[i] != 0)
				rotate(i, dirs[i]);
	}

	Calc();
	cout << cnt;
}