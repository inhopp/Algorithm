#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
using namespace std;


int main()
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s1, s2;

    cin >> n;

    while (n > 0)
    {
        int A[26] = { 0, };
        n--;
        cin >> s1 >> s2;

        for (auto c : s1)
            A[c - 'a']++;

        for (auto c : s2)
            A[c - 'a']--;

        bool flag = true;

        for (int i = 0; i < 26; i++)
        {
            if (A[i] != 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}