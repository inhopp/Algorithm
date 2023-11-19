#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	queue<int> Q;

	for (int i = 1; i < n + 1; i++)
		Q.push(i);

	n--;
	while (n--)
	{
		Q.pop();
		
		int v = Q.front();
		Q.pop();
		Q.push(v);
	}

	cout << Q.front();
}		