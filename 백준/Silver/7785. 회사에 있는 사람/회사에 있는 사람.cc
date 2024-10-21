#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <set>
#include <unordered_set>

using namespace std;

set<string> S;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while(N--) {
        string name, log;
        cin >> name >> log;

        if (log == "enter")
            S.insert(name);
        
        else
            S.erase(name);
    }

    for (auto it = S.rbegin(); it != S.rend(); it++)
        cout << *it << "\n";
}