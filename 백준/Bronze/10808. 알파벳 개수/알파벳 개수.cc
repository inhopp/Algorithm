#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int num = 'z' - 'a' + 1;

    int res[num];

    for (int i = 0; i < num; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        int v = (int)s[i] - 'a';
        res[v]++;
    }
    
    for (int i = 0; i < num; i++) {
        cout << res[i] << " ";
    }
}