#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int zeros, ones;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    char prev;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == prev)
            continue;

        prev = s[i];

        if (s[i]=='0')
            zeros++;
        else
            ones++;
    }

    cout << min(zeros, ones) << endl;
}