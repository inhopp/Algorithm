#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <unordered_map>

using namespace std;

unordered_map<string, string> M;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	while (N--) {
		string site, pass;
		cin >> site >> pass;

		M[site] = pass;
	}

	while (K--) {
		string site;
		cin >> site;
		cout << M[site] << "\n";
	}
}