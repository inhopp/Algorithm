#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int ans, temp;
int sign = 1;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (char c : s) {
		if (c == '+' || c == '-') {
			ans += temp * sign;

			if (c == '-')
				sign = -1;

			temp = 0;
		}

		else {
			temp *= 10;
			temp += c - '0';
		}
	}

	ans += temp * sign;
	cout << ans << endl;
}