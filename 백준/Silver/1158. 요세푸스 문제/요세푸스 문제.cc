#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <list>
#include <vector>
using namespace std;


int pre[5000];
int nxt[5000] = { 0, };

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s, len = 0;
	cin >> n >> s;

	for (int i = 1; i <= n; ++i)
	{
		pre[i] = (i == 1) ? n : i - 1;
		nxt[i] = (i == n) ? 1 : i + 1;
		++len;
	}

	vector<int> v;

	int i = 1;
	// 리스트 생성 & 제거
	for (int cur = 1; len != 0; cur = nxt[cur])
	{
		if (i == s)
		{
			pre[nxt[cur]] = pre[cur];
			nxt[pre[cur]] = nxt[cur];
			v.push_back(cur);
			i = 1;
			--len;
		}

		else
			++i;
	}

	cout << "<";
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout << ", ";
	}
	cout << ">\n";

}