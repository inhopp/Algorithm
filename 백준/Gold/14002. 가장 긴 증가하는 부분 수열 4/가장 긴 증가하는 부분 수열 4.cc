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
vector < pair<int, vector<int>>> D;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, v;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	D.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		D[i].first = 0;
		
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				if (D[i].first < D[j].first+1) {
					D[i].first = D[j].first + 1;
					D[i].second.clear();

					for (int n : D[j].second)
						D[i].second.push_back(n);
					D[i].second.push_back(A[i]);
				}
			}
		}
	}
	
	sort(D.rbegin(), D.rend());
	cout << D[0].first << endl;
	for (int n : D[0].second)
		cout << n << " ";
	cout << endl;
}