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

vector<string> V;

bool cmp(string& s1, string& s2) {
    // int mn = min(s1.size(), s2.size());
    
    // if (s1.substr(0, mn) == s2.substr(0, mn))  {
    //     int idx1 = min(mn + 1, int(s1.size()));
    //     int idx2 = min(mn + 1, int(s2.size()));

    //     return s1[idx1 - 1] > s2[idx2 - 1];
    // }

    // return s1 > s2;
    return s1 + s2 > s2 + s1;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, val;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val;
        V.push_back(to_string(val));
    }

    sort(V.begin(), V.end(), cmp);

    string answer = "";
    if (V[0][0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    for(string s : V) {
        cout << s;
    }
    cout << endl;
    return 0;
}