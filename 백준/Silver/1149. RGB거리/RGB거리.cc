#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int N;
int RE[1002];
int GE[1002];
int BE[1002];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int r, g, b;
	for (int i = 1; i <= N; i++)
	{
		cin >> r >> g >> b;

		RE[i] = min(GE[i - 1], BE[i - 1]) + r;
		GE[i] = min(RE[i - 1], BE[i - 1]) + g;
		BE[i] = min(RE[i - 1], GE[i - 1]) + b;
	}
	
	int price;
	price = min({ RE[N], GE[N], BE[N] });
	cout << price << "\n";
}