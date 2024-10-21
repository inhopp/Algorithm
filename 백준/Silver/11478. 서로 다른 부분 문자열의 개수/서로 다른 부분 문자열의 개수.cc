#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

unordered_set<string> S;

int main(void)
{
	
    // freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j <= s.length() - i; j++) {
			S.insert(s.substr(j, i));
		}
	}

	cout << S.size() << endl;
}