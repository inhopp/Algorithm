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

int A[5005];
int D[5005];

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	string N;
	cin >> N;

	if (N[0] == '0') {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < N.size(); i++) {
		A[i+1] = N[i] - '0';

		if (N[i] < '0' || N[i] > '9') {
			cout << 0 << endl;
			return 0;
		}
	}

	D[0] = 1;
	D[1] = 1;
	D[N.size() + 1] = 1;

	for (int i = 2; i <= N.size(); i++) {

		if (A[i] == 0) {
			if (A[i - 1] > 2 || A[i - 1] == 0) {
				cout << 0 << endl;
				return 0;
			}

			else {
				D[i - 1] = D[i - 2];
				D[i] = D[i - 1];
				continue;
			}
		}

		if (A[i - 1] > 0 &&  A[i - 1] * 10 + A[i] <= 26) {
			D[i] = (D[i - 1] + D[i - 2]) % 1000000;
		}

		else
			D[i] = D[i - 1];
	}

	cout << D[N.size()] << endl;
}