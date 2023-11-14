#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
using namespace std;


int main()
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int A[26] = { 0, };

    for (auto c : s1)
        A[c - 'a']++;

    for (auto c : s2)
        A[c - 'a']--;

    int res = 0;
    for (int i = 0; i < 26; i++)
        res += abs(A[i]);

    cout << res;
}