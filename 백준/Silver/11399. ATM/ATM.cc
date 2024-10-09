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

vector<int> V;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, val;
	cin >> N;

	for(int i=0; i<N; i++) {
		cin >> val;
		V.push_back(val);
	}

	sort(V.begin(), V.end());

	int sum = 0, res = 0;
	for (int& v : V) {
		sum += v;
		res += sum;
	}

	cout << res << endl;
}