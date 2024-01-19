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
vector<pair<int, string>> V;

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		V.push_back({ s.length(), s });
	}

	sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    
	for (auto v : V)
		cout << v.second << "\n";
}