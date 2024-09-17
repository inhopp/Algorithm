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

int A[100005][3];
int D[100005][3];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int idx = 1;
	while (true) {
		int N;
		cin >> N;

		if (N == 0)
			return 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < 3; j++)
				cin >> A[i][j];

		D[0][0] = 1001;
		D[0][1] = A[0][1];
		D[0][2] = A[0][1] + A[0][2];

		for (int i = 1; i < N; i++) {
			D[i][0] = min(D[i - 1][0], D[i - 1][1]) + A[i][0];
			D[i][1] = min({ D[i - 1][0], D[i - 1][1], D[i - 1][2], D[i][0] }) + A[i][1];
			D[i][2] = min({ D[i - 1][1], D[i - 1][2], D[i][1] }) + A[i][2];
		}

		cout << idx << ". " << D[N-1][1] << endl;
		idx++;
	}
}