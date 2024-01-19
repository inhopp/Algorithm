#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int n;
string s;
vector<string> V;
vector<long long> V2;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		V.push_back(s);
	}

	for (auto s : V)
	{
		reverse(s.begin(), s.end());
		V2.push_back(stoll(s));
	}

	sort(V2.begin(), V2.end());

	for (auto v : V2)
		cout << v << "\n";

}