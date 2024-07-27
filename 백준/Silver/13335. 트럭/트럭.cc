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

queue<int> T;
queue<int> B;

int N, W, L;
int res, onBridge, sum, total;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> W >> L;
	int v;
	for (int i = 0; i < N; i++) {
		cin >> v;
		total += v;
		T.push(v);
	}

	for (int i = 0; i < W; i++)
		B.push(0);

	while (sum < total) {
		res++;

		sum += B.front();
		onBridge -= B.front();
		B.pop();

		if (T.empty())
			continue;

		if (onBridge + T.front() > L) {
			B.push(0);
		}

		else {
			onBridge += T.front();
			B.push(T.front());
			T.pop();
		}
	}

	cout << res << endl;
}