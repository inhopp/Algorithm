#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int n;
int B[100000];
int D[100000];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
		D[i] = 1;
	}

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (B[j] < B[i])
				D[i] = max(D[i], D[j] + 1);

	int mx = *max_element(D, D + n);

	cout << mx << "\n";
}