#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int board[128][128];
int num_cnt[2] = { 0, 0 }; // white, blue

int check(int r, int c, int size)
{
	int startColor = board[r][c];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (board[r + i][c + j] != startColor)
				return -1;

	return startColor;
}

void func(int r, int c, int size)
{
	int ch = check(r, c, size);
	if (size == 1 || ch != -1)
	{
		num_cnt[ch]++;
		return;
	}

	int half = size >> 1;
	func(r, c, half);
	func(r + half, c, half);
	func(r, c + half, half);
	func(r + half, c + half, half);
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	func(0, 0, n);

	cout << num_cnt[0] << '\n';
	cout << num_cnt[1];
}