#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int board[7000][7000];

// * = 1, " " = 0


void fill(int r, int c, int size)
{
	if (size == 3)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j <= i; j++)
			{
				if (i == 1 && j == 0) continue;

				board[r + i][c + j] = 1;
				board[r + i][c - j] = 1;
			}

		return;
	}

	size = size >> 1;
	fill(r, c, size);
	fill(r + size, c - size, size);
	fill(r + size, c + size, size);
}



int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int size;
	cin >> size;


	int num_tri = size / 3;
	int width = num_tri * 5 + num_tri - 1;

	fill(0, (width - 1) / 2, size);
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == 0)
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}
}
