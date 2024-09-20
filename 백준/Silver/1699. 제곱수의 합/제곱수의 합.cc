#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
#include <math.h>

using namespace std;

int D[100005];

int main(void)
{
	// freopen("input.txt", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		D[i] = i;
		
		for (int j = 0; j <= i; j++) {
			if (j * j > i) break;

			D[i] = min(D[i], D[i - j * j] + 1);
		}
	}

	cout << D[N] << endl;
}