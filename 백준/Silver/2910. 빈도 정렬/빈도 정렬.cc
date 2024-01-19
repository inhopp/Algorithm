#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
using namespace std;

int n;
long long c, val;
long long arr[1000];
map<long long, int> M;
vector<pair<long long, int>> V;

bool cmp(const pair<long long, int>& e1, const pair<long long, int>& e2)
{
	return e1.second > e2.second;
}


int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> val;
		arr[i] = val;
	}

	for (int i = 0; i < n; i++)
		M[arr[i]] += 1;

	for (int i = 0; i < n; i++)
	{
		val = arr[i];

		bool ch = false;
		for (auto v : V)
		{
			if (v.first == val)
			{
				ch = true;
				break;
			}
		}

		if (ch) continue;

		V.push_back({ val, M[val] });
	}

	stable_sort(V.begin(), V.end(), cmp);

	for (auto v : V)
	{
		int cnt = v.second;
		for (int i = 0; i < cnt; i++)
			cout << v.first << " ";
	}
}