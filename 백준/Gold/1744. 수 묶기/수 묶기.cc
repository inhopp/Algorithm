#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

vector<int> Pos;
vector<int> Neg;

long long ans;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, val, size;
	cin >> N;

	bool has_zero = false;

	for (int i = 0; i < N; i++) {
		cin >> val;

		if (val > 0)
			Pos.push_back(val);
		else if (val < 0)
			Neg.push_back(val);
		else
			has_zero = true;
	}

	sort(Pos.begin(), Pos.end());
	sort(Neg.begin(), Neg.end());

	size = static_cast<int>(Neg.size());
	if (size % 2 == 1 && !has_zero)
		ans += Neg[size - 1];
	
	for (int i = 0; i < size - 1; i += 2) {
		ans += Neg[i] * Neg[i + 1];
	}

	size = static_cast<int>(Pos.size());
	if (size % 2 == 1)
		ans += Pos[0];

	for (int i = size - 1; i >= 1; i -= 2) {
		if (Pos[i] == 1 || Pos[i - 1] == 1)
			ans += (Pos[i] + Pos[i - 1]);
		else
			ans += Pos[i] * Pos[i - 1];
	}

	cout << ans << endl;
}