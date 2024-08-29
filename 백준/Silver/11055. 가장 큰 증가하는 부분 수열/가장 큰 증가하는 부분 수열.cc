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

int A[1005];
int D[1005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		D[i] = A[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (A[j] < A[i]) {
				D[i] = max(D[i], D[j] + A[i]);
			}
		}
	}

	cout << *max_element(D, D + N) << endl;
}