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

#define X first
#define Y second

vector<pair<int, int>> A;
vector<pair<int, int>> B;
int P[14];

int N, M, v, res=5000;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> v;

			if (v == 1)
				A.push_back({ i,j });

			else if (v == 2)
				B.push_back({ i,j });
		}

	for (int i = B.size() - M; i < B.size(); i++)
		P[i] = 1;

	do {
		vector<pair<int, int>> Temp;

		for (int i = 0; i < B.size(); i++)
			if (P[i] == 1)
				Temp.push_back(B[i]);

		int sum = 0;
		for (auto a : A) {
			int dist = 5000;

			for (auto t : Temp) {
				dist = min(dist, abs(a.X - t.X) + abs(a.Y - t.Y));
			}

			sum += dist;
		}

		res = min(res, sum);
	} while (next_permutation(P, P + B.size()));

	cout << res << endl;
}