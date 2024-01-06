#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int N;
int mx;

int Board[20][20];
int BoardOrigin[20][20];
int temp[20];

void rotate(bool CW)
{
	int rotateTemp[20][20];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			rotateTemp[i][j] = Board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (CW) Board[i][j] = rotateTemp[N - 1 - j][i];
			else Board[i][j] = rotateTemp[j][N - 1 - i];
		}
}

void func()
{
	for (int i = 0; i < N; i++)
	{
		fill(temp, temp + 20, 0);

		int idx = 0;

		for (int j = 0; j < N; j++)
		{
			if (Board[i][j] == 0) continue;

			if (temp[idx] == 0)
				temp[idx] = Board[i][j];

			else if (temp[idx] == Board[i][j])
				temp[idx++] *= 2;

			else
				temp[++idx] = Board[i][j];
		}

		for (int j = 0; j < N; j++)
			Board[i][j] = temp[j];
	}
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> BoardOrigin[i][j];

	for (int rot = 0; rot < 1024; rot++)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				Board[i][j] = BoardOrigin[i][j];

		int brute = rot;

		for (int step = 0; step < 5; step++)
		{
			int dir = brute % 4;

			for (int i = 0; i < dir; i++)
				rotate(true);

			func();

			for (int i = 0; i < dir; i++)
				rotate(false);

			brute /= 4;
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (Board[i][j] > mx) mx = Board[i][j];
	}

	cout << mx;
}