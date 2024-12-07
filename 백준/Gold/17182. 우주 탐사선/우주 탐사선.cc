#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <math.h>
#include <tuple>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int D[11][11];
int S[11];
int N, K;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> D[i][j];

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	vector<int> P;
	for (int i = 0; i < N; i++) {
		if (i == K) continue;
		P.push_back(i);
	}
	
	int answer = 0x7f7f7f7f;

	do {
		int cur = K;
		int temp = 0;

		for (int nxt : P) {
			temp += D[cur][nxt];
			cur = nxt;
		}

		answer = min(answer, temp);

	} while (next_permutation(P.begin(), P.end()));

	cout << answer << endl;

	return 0;
}