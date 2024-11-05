#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_set<string> US;

bool cmp(string& s1, string& s2)
{
    if (s1.substr(0, 2) != s2.substr(0, 2))
        return s1.substr(0, 2) < s2.substr(0, 2);

    else
        return s1.substr(3, 5) < s2.substr(3, 5);
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    string S, E, Q;
    cin >> S >> E >> Q;

    int answer = 0;

    while(true) {
        string time, name;
        cin >> time >> name;

        if (time == "")
            break;

        if (time <= S) {
            US.insert(name);
        }

        if (E <= time && time <= Q) {
            if (US.find(name) == US.end())
                continue;

            US.erase(name);
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}