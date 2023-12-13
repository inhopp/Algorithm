#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int board[6500][6500];

// * = 1, " " = 0
void fill(int r, int c, int size)
{
	if (size == 3)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1) board[r + i][c + j] = 0;
				else board[r + i][c + j] = 1;
			}

		return;
	}

	int part = size / 3;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) continue;
			else fill(r + i * part, c + j * part, part);
		}
			
}



int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int size;
	cin >> size;

	fill(0, 0, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 1)
				cout << "*";
			else
				cout << " ";
		}

		cout << "\n";
	}
}